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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* first = head;
        while (first && first->next) {
            ListNode* second = first->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // update
            prev = first;
            first = first->next; 
        }
        return dummy->next;
    }
};