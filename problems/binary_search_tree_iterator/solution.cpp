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
        this->inorder(root);
    }
    
    int next() {
        TreeNode* topNode = this->st.top();
        st.pop();
        if (topNode->right){
            this->inorder(topNode->right);
        }
        return topNode->val;
    }
    
    bool hasNext() {
        return this->st.size() > 0;
    }
    
    void inorder(TreeNode* root){
        // add all elements in the leftmost branch to the stack
        while (root){
            this->st.push(root);
            root = root->left;
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