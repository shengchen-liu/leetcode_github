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
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return helper(root, pre);
    }
    
    bool helper(TreeNode* node, TreeNode* &pre) {
        if (!node) return true;
        bool res = helper(node->left, pre);
        if (!res) return false;
        if (pre) {
            if (node->val <= pre->val) return false;
        }
        pre = node;
        return helper(node->right, pre);
    }
};