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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> st;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            // 1. num > st.back().val
            while (!st.empty() && st.back()->val < nums[i]) {
                cur->left = st.back();
                st.pop_back();
            }
            if (!st.empty()) {
                st.back()->right = cur;
            }
            st.push_back(cur);
        }
        return st.front();
    } 
};