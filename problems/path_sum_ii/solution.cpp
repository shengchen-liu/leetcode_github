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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> result;
        helper(root, path, result, sum);
        return result;
    }
    void helper(TreeNode* node, vector<int> &path, vector<vector<int>> &result, int sum){
        if (!node){
            return;
        }
        path.push_back(node->val);
        if (!node->left && !node->right && node->val == sum){
            result.push_back(path);
        }
        helper(node->left, path, result, sum - node->val);
        helper(node->right, path, result, sum - node->val);
        path.pop_back();
    }
};