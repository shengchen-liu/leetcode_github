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
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        dfs(root, 0, cnt);
        return cnt;
    }
    
    void dfs(TreeNode* node, int path, int &cnt) {
        // termination
        if (!node)
            return;
        
        // recursion
        path = path ^ (1 << node->val);
        // if it's a leaf check if the path is good
        if (!node->left && !node->right){
            // at most 1 digit has odd frqency
            if ((path & (path - 1)) == 0)
                ++cnt;
        }
        dfs(node->left, path, cnt);
        dfs(node->right, path, cnt);
    }
};