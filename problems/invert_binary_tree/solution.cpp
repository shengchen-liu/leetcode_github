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
in-order traversal
4, 2, 1, 3, 7, 6, 9
      node
left(i)  right(i)
node->right = left(i)
node->left = right(i)
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    
    // inverse subtree starting from current node
    void helper(TreeNode* node) {
        // termination
        if (!node) return;
        
        // recursion
        helper(node->left);
        helper(node->right);
        TreeNode* tmp = node->left;
        node->left= node->right;
        node->right = tmp;
        return;
    }
};