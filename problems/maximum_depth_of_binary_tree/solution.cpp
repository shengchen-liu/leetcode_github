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
    int maxDepth(TreeNode* root) {
        int res = 0;
        res = dfs(root);
        return res;
    }
    
    // maxDepth starting from node
    int dfs(TreeNode* node) {
        // termination
        if (!node) return 0;
        
        // recursion
        int tmp = max(dfs(node->left), dfs(node->right)) + 1;
                
        return tmp;
        
    }
};