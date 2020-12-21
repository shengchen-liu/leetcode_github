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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int cnt = 0;
        while(cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            // left most node
            cur = st.top();
            st.pop();
            ++cnt;
            if (cnt == k)
                return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};