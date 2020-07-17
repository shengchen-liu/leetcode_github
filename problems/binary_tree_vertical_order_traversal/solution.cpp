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

/*
BFS
*/
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> m; // treemap
        queue<pair<int, TreeNode*>> q; // {col_num, TreeNode*}
        if (!root) return {};
        q.push({0, root});
        //BFS
        int col = 0;
        while (!q.empty()) {
            auto a = q.front(); // node: 3
            int col = a.first;
            TreeNode* node = a.second;
            m[col].push_back(node->val);
            q.pop();
            if (node->left) {
                q.push({col - 1, node->left});
            }
            if (node->right) {
                q.push({col + 1, node->right});
            }
        }
        
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};