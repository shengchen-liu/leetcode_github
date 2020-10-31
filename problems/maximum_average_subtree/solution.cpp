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
    
    double ans = 0.00;
    
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    pair<int, int> dfs(TreeNode* root)
    {
        if(!root) return {0,0};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        int sum = root->val + left.first + right.first;
        int c = 1 + left.second + right.second;
        
        double ansval = double(sum)/c;
        ans = max(ans, ansval);
        return {sum, c};
    }
};