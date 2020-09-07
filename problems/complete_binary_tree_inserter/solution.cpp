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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        tree_root = root;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            if (!t->left || !t->right) break;
            q.push(t->left);
            q.push(t->right);
            q.pop();
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        // the parent is the 1st node in the q
        auto t = q.front();
        if (!t->left) t->left = node;
        // t has left, but no right
        else {
            t->right = node;
            q.push(t->left);
            q.push(t->right);
            q.pop();
        }
        return t->val;
    }
    
    TreeNode* get_root() {
        return tree_root;
    }
    
private:
    TreeNode* tree_root;
    queue<TreeNode*> q;
    
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */