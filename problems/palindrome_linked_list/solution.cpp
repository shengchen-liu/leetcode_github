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
 /*
 reverse 2nd half

 1 -> 2 -> 2 -> 1
 i
 j
      i
           j


1 -> 2 -> 2 -> 2 -> 1
ij
     i    j
          i        j

               q

1 -> 2 -> 2 -> 2 <- 1
p                   q
         

 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* first = head;
        // find 2nd half
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverseList(slow->next);
        ListNode* firstHalf = head;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};