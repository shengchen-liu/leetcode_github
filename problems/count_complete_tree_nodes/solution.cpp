/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(N)
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (!root) return 0;
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
// };

// class Solution {
// public: 
//     int countNodes(TreeNode* root) {
//         int hLeft = leftHeight(root);
//         int hRight = rightHeight(root);
//         if (hLeft == hRight) return pow(2, hLeft) - 1;
//         return countNodes(root->left) + countNodes(root->right) + 1;
//     }
//     int leftHeight(TreeNode* root) {
//         if (!root) return 0;
//         return 1 + leftHeight(root->left);
//     }
//     int rightHeight(TreeNode* root) {
//         if (!root) return 0;
//         return 1 + rightHeight(root->right);
//     }
    
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        int res = 0, h = getHeight(root);
        if (h < 0) return 0;
        while (root) {
            if (getHeight(root->right) == h - 1) {
                res += 1 << h;
                root = root->right;
            } else {
                res += 1 << (h - 1);
                root = root->left;
            }
            --h;
        }
        return res;
    }
    int getHeight(TreeNode* node) {
        return node ? (1 + getHeight(node->left)) : -1;
    }
};