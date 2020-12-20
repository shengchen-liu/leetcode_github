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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = findSize(head); // length of list
        
        return dfs(0, n - 1, head);
    }
    
    int findSize(ListNode* head) {
        int cnt = 0;
        while (head){
            head = head->next;
            ++cnt;
        }
        return cnt;
    }
    
    TreeNode* dfs(int start, int end, ListNode *&head){
        // termination
        if (start > end)
            return NULL;
        
        int mid = start + (end - start) / 2;
        
        // left
        TreeNode* l = dfs(start, mid - 1, head);
        
        // node
        TreeNode* node = new TreeNode(head->val);
        node->left = l;
        
        head = head->next;

        // right
        TreeNode* r =  dfs(mid + 1, end, head);

        node->right = r;
        
        return node;
    } 
};