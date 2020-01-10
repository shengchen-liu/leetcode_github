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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);  
        ListNode* cur = result;
        int carry = 0;
        while(l1 || l2){
            int val_1 = l1 ? l1->val : 0;  //2, 4, 3
            int val_2 = l2 ? l2->val : 0;  //5, 6, 4
            int digit = val_1 + val_2 + carry;  //7, 10, 8
            int sum = digit % 10; // 7, 0, 8
            carry = digit / 10; //0, 1, 0
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            cur->next = new ListNode(sum); //[7] [0] [8]
            cur = cur->next;
        }
        if(carry > 0) cur->next = new ListNode(1);
        return result->next;
    }
    
};