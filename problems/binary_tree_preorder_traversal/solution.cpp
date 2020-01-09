/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// divide & conquer
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if (root == NULL) return result;

//         vector<int> left_results = preorderTraversal(root->left);
//         vector<int> right_results = preorderTraversal(root->right);
//         result.push_back(root -> val);
//         result.insert(result.end(), left_results.begin(), left_results.end());
//         result.insert(result.end(), right_results.begin(), right_results.end());
        
//         return result;
            

//     }
// };

class Solution{
  public:
    vector<int> preorder;

    void traverse(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        preorder.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        preorder.clear();
        traverse(root);
        return preorder;
    }
};