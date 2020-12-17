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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> setNodes(nodes.begin(), nodes.end());
        TreeNode* res = dfs(root, setNodes);
        return res;
    }
    
    // return highest node in nodes
    TreeNode* dfs(TreeNode* node, unordered_set<TreeNode*> &setNodes) {
        // terminaiotn
        if (!node)
            return NULL;
        
        // recursion
        if (setNodes.count(node))
            return node;
        
        TreeNode* left = dfs(node->left, setNodes);
        TreeNode* right = dfs(node->right, setNodes);
        
        if (left && right)
            return node;
        else if (left)
            return left;
        else return right;
    }
};