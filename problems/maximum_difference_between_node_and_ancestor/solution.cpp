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
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        return helper(root, root->val, root->val);
    }
    
    int helper(TreeNode* node, int curMax, int curMin){
        // return the max diff from node to any its leaves
        if (!node)
            return curMax - curMin;
        
        curMax = max(curMax, node->val);
        curMin = min(curMin, node->val);
        int left = helper(node->left, curMax, curMin);
        int right = helper(node->right, curMax, curMin);
        return max(left, right);
    }
};