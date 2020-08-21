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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        // if root is a leaf
        if (!root->left && !root->right) {
            if (root->val == sum) return true;
            else return false;
        }
        if (hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val))
            return true;
        return false;
        
    }
};