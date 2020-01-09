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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL){
            return depth;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};