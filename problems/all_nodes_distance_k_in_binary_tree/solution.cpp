/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
1. find target node
    dfs
2. find nodes that has distance K from target's subtree
    findDown(node, K): dfs
3. find nodes upward
    findUp(node, K)
    
hashmap node: parent
3 : null
5 : 3
6 : 5
2 : 5
7 : 2
4 : 1
1 : 3
0 : 1
8 : 1
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        findParent(root, NULL, parent);
        vector<int> res;
        helper(target, K, parent, visited, res); // root := 5, k:=2
        return res;
    }
    
    void findParent(TreeNode* node, TreeNode* up, unordered_map<TreeNode*, TreeNode*>& parent) {
        // termination
        if (!node) return;
        
        // recursion
        parent[node] = up;
        // left child
        findParent(node->left, node, parent);
        // right child
        findParent(node->right, node, parent);
    }
    
    void helper(TreeNode* node, 
                int k, 
                unordered_map<TreeNode*, TreeNode*>& parent,
                unordered_set<TreeNode*> &visited,
                vector<int>& res) {
        // termination
        if (!node) return;
        if (visited.count(node)) return;
        visited.insert(node);
        if (k == 0) {
            res.push_back(node->val);
            return;
        }
        
        // recursion
        helper(node->left, k - 1, parent, visited, res); // 
        helper(node->right, k - 1, parent, visited, res);
        helper(parent[node], k - 1, parent, visited, res);


    }
};