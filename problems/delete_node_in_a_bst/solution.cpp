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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // termination
        if (!root) return NULL;
        
        // recursion
        // 1. find the node
        if (key > root->val) root->right = deleteNode(root->right, key);
        else if (key < root->val) root->left = deleteNode(root->left, key);
        else { // find it
            // 2.1 node is a leaf
            if (!root->left && !root->right)
                root = NULL;
            else if (root->right) {
                // 2.2 node has right subtree
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                // 2.3 node has no right but has left subtree
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
    
    // 1 step left, then always right
    int predecessor(TreeNode* node) {
        node = node->left;
        while (node->right)
            node = node->right;
        return node->val;
    }
    
    // 1 step right, then always left
    int successor(TreeNode* node) {
        node = node->right;
        while (node->left)
            node = node->left;
        return node->val;
    }
    
    
};