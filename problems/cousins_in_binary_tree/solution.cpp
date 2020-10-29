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
 cousins[x, y]: same depth, different parents
 find node_x : depth, parent
 dfs
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int d_y = -1;
        int d_x = -2;
        TreeNode* x_par;
        TreeNode* y_par;
        helper(root, x, y, NULL, x_par, y_par, d_x, d_y, 0);
        return d_x == d_y && x_par != y_par;
    }
    
    void helper(TreeNode* node, int x, int y, 
                TreeNode* parent,
                TreeNode*& x_par, TreeNode*& y_par, 
                int& d_x, int& d_y,
               int depth){
        // termination
        if (!node) return;
        
        // recursion
        if (node->val == x){
            x_par = parent;
            d_x = depth;
        } else if (node->val == y) {
            y_par = parent;
            d_y = depth;
        } else{
            helper(node->left, x, y, node, x_par, y_par, d_x, d_y, depth + 1);
            helper(node->right, x, y, node, x_par, y_par, d_x, d_y, depth + 1);
        }
    }
};