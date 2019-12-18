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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        TreeNode * head;
        queue<TreeNode*> q{{root}};
        vector<vector<int>> result;
        
        while(!q.empty()){
            // layer operation
            vector<int> layer;
            int size = q.size();
            for (int i = 0; i < size; i++){
                head = q.front(); //first element
                layer.push_back(head->val);
                q.pop();
                // q has children?
                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
            }
            result.push_back(layer);
        }
        return result;
    }
};