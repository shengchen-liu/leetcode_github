/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// pre-order traversal
// As we traverse, we compare the current node with its parent node to determine if it is consecutive. If not, we reset the length.
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
    int helper(TreeNode* root, TreeNode* parent, int len) {
        if (!root) {
            return len;
        }
        len = (parent && root->val == parent->val + 1) ? len + 1 : 1;
        return max(len, max(helper(root->left, root, len),
                            helper(root->right, root, len)));
    }
};