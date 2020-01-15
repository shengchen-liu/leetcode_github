/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// RECURSION
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL) return head;
//         if (head->next == NULL) return head; //5
//         ListNode* p = reverseList(head->next); //p:5, head:1
//         head->next->next = head; //5=>4, 4=>3, 3=>2, 2=>1
//         head->next = NULL;
//         return p;
//     }
// };

// ITERATION
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *temp;
    
		while(head!= NULL)
		{
			temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
		
		return prev;
	}
};