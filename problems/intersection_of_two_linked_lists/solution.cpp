/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 A: [4,1,8,4,5]
 B: [5,6,1,8,4,5]
 A: a ptr
 B: b ptr
 &a == &b => intersection
 len_a: 5.  len_b: 6
 comapare:
 
while (len_a >0 and len_b > 0)
 (1) len_a == len_b:
    &a vs &b: true => return a
              false=> move a, move b. --len_a, --len_b
 (2) len_a > len_b:
    move a, --len_a
 (3) len_a < len_b:
    move b, --len_b

return null
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
        } else {
            for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
        }
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB) ? headA : NULL;
    }
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
};