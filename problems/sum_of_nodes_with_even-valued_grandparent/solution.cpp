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
 return sum of vals in a tree starting with current node
f(node, grandparent, &sum) 
 1. node is valid =>
    cur = 
        if (node's grandparent is even) return node->val
        else return 0
    node has left and right children
        node
       /   \
      left  right
          6 
        /   \ 
      7       8
     / \     / \
    2   7   1   3
    left_sum = f(node->left)
    right_sum = f(node->right)
    return left_sum + right_sum + cur 
2. node is null
    return 0
    
*/
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }
    
    //  return sum of vals in a tree starting with current node
    int dfs(TreeNode* node, TreeNode* p, TreeNode* gp){
        // termination
        if (!node) return 0;
        
        // recursion
        int cur = 0;
        if (gp && gp->val % 2 == 0) {
            cur = node->val;
        }
        
        // leftsum, rightsum
        int left_sum = dfs(node->left, node, p);
        int right_sum = dfs(node->right, node, p);
        return cur + left_sum + right_sum;
    }
};