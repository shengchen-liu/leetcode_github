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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> inOrder;
        TreeNode* node = root;

        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                node = node->left;
            } 
            node = s.top();
            s.pop();
            inOrder.push_back(node->val);
            node = node->right;      
        }
        return inOrder;
    }
};