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
1. root is null => return {}
2. root has left and right
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;    
        if (!root) return res;
        helper(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void helper(TreeNode* node, int level, vector<vector<int>> &res) {
        if (res.size() == level) {
            res.push_back({});
        }
        
        res[level].push_back(node->val);
        
        if (node->left) helper(node->left, level + 1, res);
        if (node->right) helper(node->right, level + 1, res);
    }
};