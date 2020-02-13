/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// if a node is root => yes
// if a node has both n1 and n1 => compare n1.left vs n2.right and n1.right vs. n2.left
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;
//         return checkSymmetry(root->left, root->right);
//     }
//     bool checkSymmetry(TreeNode* left, TreeNode* right) {
//         if (!left && !right) return true;
//         if (!left && right || left && !right || left->val != right->val) return false;
//         return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
//     }
// };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left); // [2]
        q2.push(root->right); // [2]
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* n1 = q1.front();
            q1.pop();
            TreeNode* n2 = q2.front();
            q2.pop();
            if (!n1 && !n2) continue;
            if ((!n1 && n2) || (n1 && !n2) || (n1->val != n2->val)) return false;
            q1.push(n1->left);
            q1.push(n1->right);
            q2.push(n2->right);
            q2.push(n2->left);
        }
        return true;
    }    
};