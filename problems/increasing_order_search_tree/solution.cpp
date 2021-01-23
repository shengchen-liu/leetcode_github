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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = helper(root, NULL);
        return res;
    }
    
    TreeNode* helper(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = helper(root->left, root);
        root->left = NULL;
        root->right = helper(root->right, tail);
        return res;
    }
};