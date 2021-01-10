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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* i = head;
        ListNode* n_k = head;
        int val_k = 0;
        while (i){
            ++len;
            if (len == k){
                val_k = i->val;
                n_k = i;
            }
            i = i->next;
        }
        
        int j = len - k;
        i = head;
        while (j > 0){
            --j;
            i = i->next;
        }
        int val_j = i->val;
        i->val =val_k;
        n_k->val = val_j;
        return head;
        
    }
};