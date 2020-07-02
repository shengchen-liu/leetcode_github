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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        helper(root, res, 0);
        return res;
    }
    
    void helper(TreeNode *node, vector<int> &res, int level) {
        if (!node) return;
        if (level + 1 > res.size()) { // new level
            res.push_back(node->val); // res: [1] size = 1
        }
        if (node->right) helper(node->right, res, level + 1);
        if (node->left) helper(node->left, res, level + 1);
    }
};