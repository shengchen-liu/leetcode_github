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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool leftToRight = true;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> layer(n);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int idx = leftToRight ? i : (n - 1 - i);
                layer[idx] = node->val; //[1], [3, 2], [4, 5]
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            res.push_back(layer);
        }
        return res;
    }
};