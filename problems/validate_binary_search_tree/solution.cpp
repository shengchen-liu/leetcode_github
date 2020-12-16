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

/*
low < node < high
for each node:
    update low, high
    compare node's val vs low,high
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    
    bool dfs(TreeNode* node, long low, long high) {
        // termination
        if (!node)
            return true;
        
        // recursion
        if (node->val <= low || node->val >= high)
            return false;
        bool left_res = dfs(node->left, low, node->val);
        bool right_res = dfs(node->right, node->val, high);
        return left_res && right_res;
    }
};