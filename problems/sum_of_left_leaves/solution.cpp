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
while ths stack is non-empty
    if node->left exists and node->left is a leaf
        update sum
    else if node->left exists:
        st.push(node->left)
    else if node->right exists:
        st.push(node->right)
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        // iteration, in-order
        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            // node->left is a leaf
            if (isLeaf(node->left)) {
                sum += node->left->val;
            } 
            
            if (node->left){
                st.push(node->left);
            }
            
            if (node->right) {
                st.push(node->right);
            }       
        }
        return sum;
    }
    
    bool isLeaf(TreeNode* node) {
        return (node && (!node->left && !node->right));
    }
};