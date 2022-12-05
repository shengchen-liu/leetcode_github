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
 search 
 dfs, keep track of layer, max_depth
 if reaches to leaf, update max_depth with layer
 
pre order traverse
dfs(node, level, res)  : starting at cur node, at this level, find max_depth
    if !node:
        return
    if node is a leaf:
        res = max(level, res)
        return
    dfs(node->left, level + 1, res)
    dfs(node->right, level+1, res)
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        dfs(root, 1, res);
        return res;
    }

    void dfs(TreeNode* node, int level, int& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res = max(res, level);
            return;
        }
        dfs(node->left, level + 1, res);
        dfs(node->right, level + 1, res);
    }
};