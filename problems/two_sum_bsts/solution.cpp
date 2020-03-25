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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s;
        inHashset(root1, target, s);
        return inCheck(root2, s);
    }
    
    void inHashset(TreeNode* root, int target, unordered_set<int> &s) {
        if (!root) return;
        inHashset(root->left, target, s);
        s.insert(target - root->val);
        inHashset(root->right, target, s);
    }
    
    bool inCheck(TreeNode* root, unordered_set<int> &s) {
        if (!root) return false;
        return inCheck(root->left, s) || s.count(root->val) || inCheck(root->right, s);
    }
};