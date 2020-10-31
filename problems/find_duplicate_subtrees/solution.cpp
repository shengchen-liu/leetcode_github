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
 serialize tree, in-order
 duplicate: same structure and same node values
 leaf: 4
 node
l    r 
hashmap:
2: 1
4: 1
5: 1
3, 4, 5: 1
1, 2, 3, 4, 5: 1
dfs. 
tree_serial = node, serial(node->left), serial(node->right)
check if tree_serial in hashset:
    true=> res.push_back node
    flase=> hashset.insert(tree_serial)
    
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> res;
        helper(root, m, res);
        return res;
        
    }
    
    // serialize a subtree 
    string helper(TreeNode* node, 
                  unordered_map<string, int>& m, 
                  vector<TreeNode*>& res) {
        if (!node) return "#";
        string tmp = to_string(node->val) + "," + 
            helper(node->left, m, res) + "," 
            + helper(node->right, m, res);
        if (!m.count(tmp)) {
            m[tmp] = 1;
        } else {
            ++m[tmp];
        }
        
        if (m[tmp] == 2) res.push_back(node);
        return tmp;
            
    }
};