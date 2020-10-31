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
 DFS
 sum = 0
 update sum based on path
 100, 101, 110, 111
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    
    void helper(TreeNode* node, int cur_sum, int &sum) {
        // termination
        if (!node) return;
        
        // recursion
        int tmp = cur_sum * 2 + node->val;
        // node is a leaf
        if (!node->left && !node->right) {
            sum += tmp;
        } else{
            helper(node->left, tmp, sum);
            helper(node->right, tmp, sum);
        }
    }
};