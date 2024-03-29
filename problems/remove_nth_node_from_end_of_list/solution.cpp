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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        first = dummy;
        // create a window
        for (int i = 0; i < n; ++i) {
            first = first->next;
            if (!first) return head;
        }

        // second node
        ListNode* second = dummy;
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};