/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
1->1->2->3->3
i: 0
j: i -> next
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode* i = head;
        ListNode* j = i ->next;
        while (j) {
            if (i->val == j->val) {
                i->next = NULL;
                j = j->next;
            }
            else {
                i->next = j;
                i = j;
                j = i->next;
            }
        }
        return head;
    }
};