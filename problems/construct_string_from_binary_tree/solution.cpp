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
    node
   /    \
lefS    rightS
2(4)      3
nodeS(lefS)(rightS)
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        // termination
        if (!t) return "";
        
        string res = to_string(t->val); //res: 1, 2

        string left = tree2str(t->left), right = tree2str(t->right);
        if (left == "" && right == "") return res;
        if (left == "") return res + "()" + "(" + right + ")";
        if (right == "") return res + "(" + left + ")";
        return res + "(" + left + ")" + "(" + right + ")";
    }
};