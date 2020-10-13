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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lHead = new ListNode();
        ListNode* rHead = new ListNode();
        
        ListNode* cur, *left, *right;
        cur = head;
        left = lHead;
        right = rHead;
        
        while (cur) {
            if (cur->val < x) {
                left->next = cur;
                left = cur;
            } else {
                right->next = cur;
                right = cur;
            }
            cur = cur->next;
        }
        right->next = NULL;
        
        if (rHead->next) {
            left->next = rHead->next;
        }
        
        return lHead->next;
        

    }
};