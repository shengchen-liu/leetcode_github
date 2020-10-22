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
    int largestBSTSubtree(TreeNode* root) {
                vector<int> res = helper(root);
        return res[2];
    }
    
    // return {min of this subtree, max of this subtree, # of nodes of this subtree}
    vector<int> helper(TreeNode* node) {
        if (!node) return {INT_MAX, INT_MIN, 0};
        
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);
        if (node->val > left[1] && node->val < right[0]) {
            return {min(node->val, left[0]), max(node->val, right[1]), left[2] + right[2] + 1};
        } else {
            return {INT_MIN, INT_MAX, max(left[2], right[2])};
        }
    }
};