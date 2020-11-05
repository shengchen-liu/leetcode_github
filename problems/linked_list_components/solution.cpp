/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
0->1->2->3->4 
G=[0, 3, 1, 4] value range: [0, N - 1].
[0, 1], [3,4]

requirements:
1. node->val is aavialble in G
0->1->2->3->4  val_in_G    next_in_G    cnt
X              T           T            ++
   x           T           F            
      X        F        
         X     T           T
            X  Not necessary

   idx 0, 1, 2, 3, 4
G1 := [1, 1, 0, 1, 1] size: N
val in G: G1[val] == 1 ? T : F;



 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> setG (G.begin(), G.end());
        int res = 0;
        while (head != NULL) {
            if (setG.count(head->val) && (head->next == NULL || !setG.count(head->next->val))) res++;
            head = head->next;
        }
        return res;
    }
};