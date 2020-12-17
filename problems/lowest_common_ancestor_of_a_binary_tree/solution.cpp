/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
top-down:
initial: found = 2

1. root = p or root = q:
    res = root
    
2. root != p and root != q:
      root
    /      \  
  {p}       {q}
  res = root
  
       root
      /    \
   {p,q}
  res = LCA(root->left)
  
      root 
      /  \
           {p,q}
  res = LCA(root->right)
  
*/


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        dfs(root, p, q, res);
        return res;
    }
    
    // whether we can find either p or q in subtree node
    bool dfs(TreeNode* node, TreeNode *p, TreeNode *q, TreeNode *& res) {
        // termination
        if (!node)
            return false;
        
        int mid = (node == p || node == q) ? 1 : 0;
        int left = dfs(node->left, p, q, res) ? 1 : 0;
        int right = dfs(node->right, p, q, res) ? 1 : 0;
        
        if (left + right + mid >= 2) {
            res = node;
        }
        
        return (left + right + mid > 0);
    }
};