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
    ListNode* plusOne(ListNode* head) {
        ListNode* cur = head;
        ListNode* right = NULL;
        // find the last node
        while (cur){
            if (cur->val != 9)  // 1 -> 9 -> 1(right) -> 9(cur) -> 9
                right = cur; // find the right most node that is not 9
            cur = cur->next;
        }
        // if all nodes are 9, create a new head
        if (!right) {
            right = new ListNode(0);
            right->next = head;
            head = right;
        }
        
        ++right->val;
        cur = right->next;
        while (cur){
            cur->val = 0;
            cur = cur->next;
        }
        return head;
    }
};