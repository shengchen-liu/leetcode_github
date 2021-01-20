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
        vector<vector<int>> res;
        //BFS
        queue<TreeNode*> q;
        if (!root)
            return res;
        q.push(root);
        while (!q.empty()) {
            // layer
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                // childs
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};