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
4: 5 + 6 + 7 + 8
*/
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
    
    void helper(TreeNode* node, int& sum){
        // termination
        if (!node) return;
        
        // recursion
        helper(node->right, sum);
        sum = node->val + sum;
        node->val = sum;
        helper(node->left, sum);
    }
};