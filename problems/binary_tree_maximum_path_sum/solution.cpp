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
 pathSum = helper(node, res): starting from node, return the longest path sum.  also update global max path sum
    if (!node):
        return 0
    if node is a leaf:
        res = max(res, node->val)
        return node->val
    leftSum = helper(node->left, res)
    rightSum = helper(node->right, res)
    pathSum = max(leftSum, RightSum) + node->val
    res = max(res, leftSum + rightSum + node->val)
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int pathSum = helper(root, res);
        return res;
    }

    int helper(TreeNode* node, int& res) {
        if (!node)
            return 0;
        if (!node->left && !node->right) {
            res = max(res, node->val);
            return node->val;
        }
        int leftSum = max(helper(node->left, res), 0);
        int rightSum = max(helper(node->right, res), 0);
        int pathSum = max(leftSum, rightSum) + node->val;
        res = max(res, leftSum + rightSum + node->val);
        return pathSum;
    }
};