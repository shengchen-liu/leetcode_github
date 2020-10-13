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
 
 helper: return the max path sum, the path must start from the current node
 1. if a node is empty: null
 2. a node is a leaf: node->val
 3. node has left and right:
    (1) pathL
    (2) pathR
    res = max(res, pathL + node->val + pathR)
    return max(pathL, pathR) + node->al
 
 */


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    
private:
//    return max path sum, the path must start from the current node
    int helper(TreeNode* node, int &res) {
        if(!node) return 0;
        int pathL = max(helper(node->left, res), 0);
        int pathR = max(helper(node->right, res), 0);
        res = max(res, pathL + pathR + node->val);
        return max(pathL, pathR) + node->val;
    }
};