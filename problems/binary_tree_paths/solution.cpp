/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// divide and conquer
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL){
            return {};
        }
        // leaf
        if (root->left == NULL && root->right == NULL) return {to_string(root->val)};
        
        vector<string> leftPaths  = binaryTreePaths(root -> left);
        vector<string> rightPaths  = binaryTreePaths(root -> right);
        
        // merge
        for (string path : leftPaths){
            result.push_back(to_string(root -> val) + "->" + path);
        }
        for (string path : rightPaths){
            result.push_back(to_string(root -> val) + "->" + path);
        }
        return result;
    }
};