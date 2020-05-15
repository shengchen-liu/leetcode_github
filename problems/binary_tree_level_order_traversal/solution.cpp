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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        // BFS
        q.push(root); // [3]
        while (!q.empty()) {
            int n = q.size();
            // layer
            vector<int> layer;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                layer.push_back(node->val);
                q.pop();
                
                // left
                if (node->left) q.push(node->left);
                // right
                if (node->right) q.push(node->right);
            }
            res.push_back(layer);
        }
        return res;
    }
};