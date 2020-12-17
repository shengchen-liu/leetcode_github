/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int cnt = 0;
        TreeNode* res = dfs(root, p, q, cnt);
        return cnt == 2 ? res : NULL;
    }
    
    TreeNode* dfs(TreeNode* node,  TreeNode* p, TreeNode* q, int &cnt) {
        if (!node)
            return NULL;
        
        TreeNode* left = dfs(node->left, p, q, cnt);
        TreeNode* right = dfs(node->right, p, q, cnt);
        if (node == p || node == q){
            ++cnt;
            return node;
        }
        
        if (left && right)
            return node;
        return left ? left : right;
    }
};