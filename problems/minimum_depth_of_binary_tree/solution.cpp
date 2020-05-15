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
    int minDepth(TreeNode* root) {
        int l = 1;
        if (!root) return 0;
        // if a node is a leaf, we return its depth
        // BFS => fisrt node that is a leaf 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // check if this node is a leaf
                if (!node->left && !node->right) return l;
                else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            ++l;
        }
        return 0;
        
    }
};