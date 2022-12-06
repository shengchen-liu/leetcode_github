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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        TreeNode* insert = new TreeNode(val);

        while(node) {
            if (val < node->val) {
                if (node->left) {
                    node = node->left;
                } else {
                    node->left = insert;
                    break;
                }
            } else {
                if (node->right) {
                    node = node->right;
                } else {
                    node->right = insert;
                    break;
                }
            }
        }
        return root? root : insert;
    }
};