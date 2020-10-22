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
 depth: max distance from leaf -> node
 {max_depth}
 {2nd max depth}
 ...
 {last max depth}
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    
    // depth: max distance from leaf -> node
    int helper(TreeNode* node, vector<vector<int>>& res) {
        // termination
        if (!node) return -1;
        
        // recursion
        // max (left depth, right depth)
        int leftDepth = helper(node->left, res);
        int rightDepth = helper(node->right, res);
        int depth = max(leftDepth, rightDepth) + 1;
        if (depth >= res.size()) res.resize(depth + 1);
        res[depth].push_back(node->val);
        return depth;
        
    }
};