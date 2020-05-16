/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) return {target->val};
        vector<int> res;
        helper(root, target, K, 0, res);
        return res;
    }
    int helper(TreeNode* node, TreeNode* target, int k, int dist, vector<int>& res) {
    	if (!node) return 0;
    	if (dist == k) {res.push_back(node->val); return 0;}
    	int left = 0, right = 0;
    	if (node->val == target->val || dist > 0) {
    		left = helper(node->left, target, k, dist + 1, res);
    		right = helper(node->right, target, k, dist + 1, res);
    	} else {
    		left = helper(node->left, target, k, dist, res);
    		right = helper(node->right, target, k, dist, res);
    	}
    	if (left == k || right == k) {res.push_back(node->val); return 0;}
    	if (node->val == target->val) return 1;
    	if (left > 0) helper(node->right, target, k, left + 1, res);
    	if (right > 0) helper(node->left, target, k, right + 1, res);
    	if (left > 0 || right > 0) return left > 0 ? left + 1 : right + 1;
    	return 0;
    }
};