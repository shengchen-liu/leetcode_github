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
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
 [_, _, _, _, _, _, _, _, _, _,  _ ]
 [R, B, _, _, _, _, _, _, _, _,  _ ]
 [R, B, R, _, B, _, _, _, _, _,  _ ]
 [_, B, R, _, _, _, _, _, _, _,  _ ]
 [_, B, R, _, _, _, _, _, _, _,  _ ]
 [_, B, R, _, _, _, _, _, _, _,  _ ]
 
 */
class Solution {
public:
    int left, right, val;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x, n = count(root);
        return max(max(left, right), n - left - right - 1) > n / 2;
    }

    int count(TreeNode* node) {
        if (!node) return 0;
        int l = count(node->left), r = count(node->right);
        if (node->val == val)
            left = l, right = r;
        return l + r + 1;
    }
};