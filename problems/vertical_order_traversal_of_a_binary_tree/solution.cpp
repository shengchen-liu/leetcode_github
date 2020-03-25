/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
map: [x, map:[y, set(val)]]
**/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> m;
        dfs(root, m, 0, 0);
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
    
    void dfs(TreeNode *node, map<int, map<int, set<int>>> &m, int x, int y) {
        if (!node) return;
        m[x][y].insert(node->val);
        dfs(node->left, m, x - 1, y + 1);
        dfs(node->right, m, x + 1, y + 1);
    }
};