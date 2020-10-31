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
 DFS
 1. leaf: its value, current depth, max_depth
 2. sum
when we see a leaf:
 1. cur_d == max_d:  update sum
 2. cur_d < max_d: do nothing
 3. cur_d > max_d: max_d = cur_d, sum = leaf.val
post-order traverse: left, right, node
 
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root)
            return 0;
        int max_d = 0;
        int sum = 0;
        dfs(root, 0, max_d, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int cur_d, int &max_d, int &sum) {
        // termination
        if (!node) return;
        
        // node is a leaf
        if (!node->left && !node->right) {
            // cur_d vs max_d
            if (cur_d == max_d)
                sum += node->val;
            else if (cur_d > max_d){
                max_d = cur_d;
                sum = node->val;
            }
        }
        
        // recursion
        dfs(node->left, cur_d + 1, max_d, sum);
        dfs(node->right, cur_d + 1, max_d, sum);
    }
};