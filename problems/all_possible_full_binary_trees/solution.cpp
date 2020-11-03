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
 binary tree:  for each node, it has 0 or 2 children
 N nodes=> return all possible binary trees
 N:=1
 node
 
 N:=2 impossible

 N:=3
    n
  /   \
 n      n
 
 N:= 4 impossible
 
 N:= 5
   n                    
 /   \
n[1]   n [3]            
     /   \
    n      n
        
        n
     /       \
    n[3]       n[1]  
  /   \
 n      n    
 
observation:
1. only when N is odd number, we have solution
2. f(N) decomposed 
for i = 1, 3, 5, ..., N - 1
    node->left = f(i),   node->right = f(N - i -1)

for a give node:
    1) node has both left and rigth childs: node->left = f(cnt)
    2> node is a leaf
level
0              n        n
                       / \
                      n   n 
 */
class Solution { 
public:
    unordered_map<int, vector<TreeNode*>> m;
    vector<TreeNode*> allPossibleFBT(int N) {
        // termination
        if (N %2 == 0) return {};
        if (N == 1) return {new TreeNode(0)};
        if (m.count(N)) return m[N];
        
        // recursion
        vector<TreeNode*> res;
        // decompose

        // left, right
        for (int i = 1; i < N; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N - i - 1);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode* cur = new TreeNode(0);
                    cur->left = a;
                    cur->right = b;
                    res.push_back(cur);
                }
            }
        }
        m[N] = res;
        return res;
    }
};