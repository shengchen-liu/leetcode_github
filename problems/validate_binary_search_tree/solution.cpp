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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    bool dfs(TreeNode* node, long min_val, long max_val){
        if (!node) return true;
        
        if (node->val <= min_val || node->val >= max_val) return false;
        
        return (dfs(node->left, min_val, node->val) && dfs(node->right, node->val, max_val));
    }
};