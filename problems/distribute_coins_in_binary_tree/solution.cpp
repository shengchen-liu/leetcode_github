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
 */
/*
  3
 / \
0   0
move1:
  2
 / \
1   0
move2:
  1
 / \
1   1

left_sub: every node := 1 => this part does not need to have moves any more
  1
 / \
1   1

node: 
    1. node.val := 1 => 0
    2. node.val :!= 1 => abs(node->val - 1)

     # -> lef + right + # - 1 
   /   \
0[1]    0[1]

*/
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    // number of excessive nodes
    int dfs(TreeNode* node, int & res) {
        if (!node) return 0;
        int L = dfs(node->left, res);
        int R = dfs(node->right, res);
        res += abs(L) + abs(R);
        return node->val + L + R - 1;
    }
};