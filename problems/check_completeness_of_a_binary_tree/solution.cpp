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
 BFS
 for each layer that is not the last layer: # of nodes := 2^layer
 queue
 for each layer:
    count # of nodes
    1. # == 2^ layer: continue
    2. # != 2^ layer: 
        a. this is the last layer
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool missing = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    if (missing) return false;
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    missing =  true;
                }
            }
        }
        return true;
    }
};