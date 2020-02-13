/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* helper(vector<int>& inorder, 
                     vector<int>& postorder,
                     int iLeft,
                     int iRight,
                     int pLeft,
                     int pRight) {
        if (iLeft > iRight || pLeft > pRight) return NULL;
        TreeNode* cur = new TreeNode(postorder[pRight]);
        int i = 0;
        for (i = iLeft; i < inorder.size(); ++i) {
            if (inorder[i] == postorder[pRight]) break;
        }
        cur->left = helper(inorder, postorder, iLeft, i - 1, pLeft, pLeft + i - iLeft - 1);
        cur->right = helper(inorder, postorder, i + 1, iRight, pLeft + i - iLeft, pRight - 1);
        return cur;    
    }
};