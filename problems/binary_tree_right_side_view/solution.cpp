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
BFS
queue
  node
  /   \
 l     r
node has right and node has left: queue push right, left
node has no right, has left : queue push left
node has no right, no left: nothing
 
layer      queue      res
0           [1]       []
1           [3,2]     [1]
2           [4,5]     [1, 3]
3           []        [1,3,4]

DFS
node 
always visit its right child first

starting from this current node, 
   node
  /     \
 d_l     d_r
 
if it's the first time visit current level, append the node to the res


*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }
    
    void helper(TreeNode* node, int level, vector<int>& res) {
        // termination
        if (!node)
            return;
        
        // recursion
        if (level == res.size()){
            res.push_back(node->val);
        }
        helper(node->right, level + 1, res);
        helper(node->left, level + 1, res);
    }
};