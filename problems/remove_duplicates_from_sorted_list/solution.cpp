/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 while (j):
    1. i->val == j->val:  j = j->next
    2. i->val != j->val: i = j. 
 
 1->1->2
 i  j
 i     j
 
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode* i = head;
        ListNode* j = head;
        while (j) {
            if (i->val == j->val) {
                j = j->next;
                i->next = j;
            }
            else {
                i->next = j;
                i = j;
            }
        }
        return head;
    }
};