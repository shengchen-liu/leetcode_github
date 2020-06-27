/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp =  [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val; 
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp); // min heap
        for (auto l : lists) {
            if (l) q.push(l);
        }
        if (q.empty()) return NULL;
        
        ListNode* res = q.top();
        q.pop();
        if (res->next) q.push(res->next);
        ListNode *tail = res;
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) q.push(tail->next);
        }
        return res;
    }
};