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
    int closestValue(TreeNode* root, double target) {
        int res = 0;
        double min_dis = DBL_MAX;
        helper(root, target, min_dis, res);
        return res;
    }
    
    void helper(TreeNode* node, double target, double &min_dis, int &res) {
        if (!node) return;
        double tmp = node->val - target;
        if (abs(tmp) < min_dis) {
            min_dis = abs(tmp);
            res = node->val;
        }
        if (tmp < 0) helper(node->right, target, min_dis, res);
        else helper(node->left, target, min_dis, res);
    }
};