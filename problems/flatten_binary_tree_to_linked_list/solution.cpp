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
    void flatten(TreeNode* root) {
        helper(root);
    }
    
    TreeNode* helper(TreeNode* node) {
        // return the last node
        if (!node) return NULL;
        
        // leaf
        if (!node->left && !node->right) return node;
        
        TreeNode* left_last = helper(node->left);
        TreeNode* right_last = helper(node->right);
        
        // if there is a left subtree
        if (left_last) {
            TreeNode* tmp = node->right;
            node->right = node->left;
            node->left = NULL;
            left_last->right = tmp;
        }

        return right_last ? right_last : left_last;
    }
};