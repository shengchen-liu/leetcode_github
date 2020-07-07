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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res > 0 ? res - 1 : 0;
    }
    
    // return the length of the diamter, the path MUST start from the current node
    int helper(TreeNode* node, int &res) {
        if (!node) return 0;
        int left = helper(node->left, res);
        int right = helper(node->right, res);
        res = max(res, left + right + 1);
        return 1 + max(left, right);
    }
};