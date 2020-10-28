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
 1. node is a leaf => uni subtree
 2. node  starting from this node, is this a subtree?
   /   \
 left[y]  right[y]
 if (leftSub && rightSub AND node->val == node->left == node=>rigtht) :
    true
    ++cnt
 */
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
        
    }
    
    // helper, starting from this node, is this a subtree?
    bool helper(TreeNode* node, int& cnt) {
        // termination
        if (!node) return true;
        
        // recursion
        bool left = helper(node->left, cnt);
        bool right = helper(node->right, cnt);
        if (left && right) {
            // 1. node is a leaf
            if (!node->left && !node->right){
                ++cnt;
                return true;
            }
            
            // 2. node has both left and right
            if (node->left && node->right && 
                node->left->val == node->right->val && 
                node->left->val == node->val) {
                ++cnt;
                return true;
            }
            
            // 3. node has only left
            if (node->left && !node->right &&  node->left->val == node->val){
                ++cnt;
                return true;
            }
            // 4. node has only right
            if (!node->left && node->right &&  node->right->val == node->val){
                ++cnt;
                return true;
            }
        }
        return false;
    }
};