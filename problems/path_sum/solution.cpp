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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //dfs
        stack<TreeNode*> st;
        if (!root)
            return false;
        
        st.push(root);
        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            if (!t->left && !t->right){
                if (t->val == targetSum)
                    return true;
            }
            if (t->left) {
                t->left->val += t->val;
                st.push(t->left);
            } 
            if (t->right) {
                t->right->val += t->val;
                st.push(t->right);
            }
        }
        return false;
    }
};