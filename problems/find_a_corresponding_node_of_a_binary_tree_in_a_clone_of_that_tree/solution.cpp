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

original_root, cloned_root
BFS traverse:
    original_node, cloned_node
    if find target:
        return cloned_node
        
*/
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* p1 = original;
        TreeNode* p2 = cloned;
        if (p1 == target)
            return p2;
        
        // traverse
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p1);
        q2.push(p2);
        
        while (!q1.empty()) {
            TreeNode* n1 = q1.front();
            q1.pop();
            TreeNode* n2 = q2.front();
            q2.pop();
            if (n1 == target)
                return n2;
            // neighbors
            if (n1->left){
                q1.push(n1->left);
                q2.push(n2->left);
            }
            if (n1->right){
                q1.push(n1->right);
                q2.push(n2->right);
            }            
        }
        return NULL;
    }
};