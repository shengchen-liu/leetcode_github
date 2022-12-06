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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    int next() {
        TreeNode* p = st.top();
        st.pop();
        if (p->right) {
            inOrder(p->right);
        }
        return p->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void inOrder(TreeNode* node) {
        // add all the left most nodes of this node
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */