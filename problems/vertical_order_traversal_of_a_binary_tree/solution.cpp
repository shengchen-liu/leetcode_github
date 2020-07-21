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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> m;
        helper(root, 0, 0, m);
        vector<vector<int>> res;
        for (auto itx : m) { // itx: pair{int, map<int, set<int>>}
            vector<int> tmp;
            for (auto ity : itx.second) {
                tmp.insert(tmp.end(), begin(ity.second), end(ity.second));
            }
            res.push_back(tmp);
        }
        return res;
    }
    
    // dfs
    void helper(TreeNode* node,
               int x,
               int y,
               map<int, map<int, set<int>>>& m){
        if (!node) return;
        m[x][y].insert(node->val);
        helper(node->left, x - 1, y + 1, m);
        helper(node->right, x + 1, y + 1, m);
    }
};