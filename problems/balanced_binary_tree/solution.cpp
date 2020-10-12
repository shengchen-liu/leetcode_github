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
       node
heightL    heightR

if abs(heightL - heightR) <= 1 => f(node) == true, height of node: 1 + max(hL, hR)
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
        
    }
    
    int depth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }

};