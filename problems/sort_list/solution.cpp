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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre;
        while (fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
        
    }
    ListNode* merge(ListNode* leftNode, ListNode* rightNode) {
        if (!leftNode) return rightNode;
        if (!rightNode) return leftNode;
        
        if (leftNode->val < rightNode->val){
            leftNode->next = merge(leftNode->next, rightNode);
            return leftNode;
        }
        else {
            rightNode->next = merge(leftNode, rightNode->next);
            return rightNode;
        }

    }
};