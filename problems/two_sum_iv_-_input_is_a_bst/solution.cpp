/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 2 + 10 > 9
// 2 + 6 < 9 
// 3 + 6 = 9
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        // build a sorted vector
        vector<int> sorted;
        helper(root, sorted);
        int l = 0;
        int r = sorted.size() - 1;
        while (l < r) {
            if (sorted[l] + sorted[r] == k) return true;
            if (sorted[l] + sorted[r] < k) ++l;
            if (sorted[l] + sorted[r] > k) --r;
        }
        return false;
    }
    
    void helper(TreeNode* node, vector<int> &sorted) {
        if (!node) return;
        helper(node->left, sorted);
        sorted.push_back(node->val);
        helper(node->right, sorted);
    }
};