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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        
        ListNode* i = head;
        ListNode* j = head->next;
        while (j) {
            if (i->val != j->val) {
                i->next = j;
                i = j;
            } else {
                i->next = NULL;
            }
            j = j->next;
        }
        return head;
        
    }
};