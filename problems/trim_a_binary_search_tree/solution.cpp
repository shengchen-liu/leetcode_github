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
 BST: 
        node
       /    \
 leftChild rightChild
 leftChild->val < node->val < node->rightChild
 pre-order traverse
    leftchild
    node.  
        if child.val in [low, high], keep it
        if child.val < low:
            child = child->right
        if child.val > high
            child = child->left
    rightChild
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return NULL;
        TreeNode* left = trimBST(root->left, low, high);
        TreeNode* right = trimBST(root->right, low, high);
        
        // 1
        if (root->val >= low && root->val <= high){
            root->left = left;
            root->right = right;
            return root;
        } else if (root->val < low) {
            return right;
        } else {
            return left;
        }
    }
    
};