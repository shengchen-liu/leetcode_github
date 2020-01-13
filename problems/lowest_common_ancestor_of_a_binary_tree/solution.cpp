/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    // 在root为根的二叉树中找A,B的LCA:
    // 如果找到了就返回这个LCA
    // 如果只碰到A，就返回A
    // 如果只碰到B，就返回B
    // 如果都没有，就返回null

// p = 6, q = 2
//  5
//6,  2

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL){
            return NULL;
        }
        if (root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //6
        TreeNode* right = lowestCommonAncestor(root->right, p, q); //2
        if (left && right){ // left, right both have values
            return root;
        }
        if (left){
            return left; 
        }
        if (right){
            return right;
        }
        return NULL;

    }
};