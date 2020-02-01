/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        while (prev->next) {
            ListNode* current = prev->next;
            while (current->next && current->next->val == current->val) {
                current = current->next;
            }
            if (current != prev->next) {
                prev->next = current->next;
            } else {
                prev = prev->next;
            }
            
        }
        return dummy->next;
        
        
    }
    
//         ListNode* deleteDuplicates(ListNode* head) {
//         
    // }
};