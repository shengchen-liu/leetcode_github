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
1, 2, 9
1  3  0

1, 2, 9, 9
1  3  0  0

from right to left:
    if num == 9:
        num = 0
    else: the 1st num that is not 9 => +1
        break

stack:
bot   top
1, 2, 3

all nums are 9: add 1 to the left
if head == 0:
    add a new node(1)
*/
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        // stack
        stack<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            st.push(cur);
            cur = cur->next;
        }
        // st: {3, 2, 1}
        while (!st.empty()) {
            cur = st.top();  // 3
            st.pop(); 
            if (cur->val == 9)
                cur->val = 0;
            else {
                cur->val++;
                break;
            }
        }
        
        if (head->val == 0) {
            // new node
            ListNode * new_head = new ListNode(1);
            new_head->next = head;
            return new_head;
        }
        return head;
    }
};