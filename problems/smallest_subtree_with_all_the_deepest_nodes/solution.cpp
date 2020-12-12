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
deepest nodes

*/
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // termination
        if (!root)
            return NULL;
        
        // recursion
        int leftDepth = findDepth(root->left);
        int rightDepth = findDepth(root->right);
        
        // compare
        if (leftDepth > rightDepth)
            return subtreeWithAllDeepest(root->left);
        if (leftDepth < rightDepth)
            return subtreeWithAllDeepest(root->right);
        // ==
        return root;
    }
    
    int findDepth(TreeNode* node){
        // termination
        if (!node)
            return 0;
        
        // recursion
        int left = findDepth(node->left);
        int right = findDepth(node->right);
        return 1 + max(left, right);
    }
};