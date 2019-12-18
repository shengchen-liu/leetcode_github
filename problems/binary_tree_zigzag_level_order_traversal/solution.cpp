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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        # define a queue
        if(root==NULL) return {};
        // queue<TreeNode*> q{{root}};
        vector<TreeNode*> q;
        q.push_back(root);
        vector<vector<int>> res;
        int count = 0; // number of layers
        bool leftToRight = true;
        
        while (!q.empty()){
            int size = q.size();
            vector<int> layer(size); 
            for(int i = 0; i < size; i++){
                // dequee
                TreeNode* head = q.front();
                q.erase(q.begin()); // remove the first element 
                int index = leftToRight ? i : (size - i -1);
                layer[index] = head -> val;
                // add children to the queue
                if(head->left){
                    q.push_back(head->left);
                }
                if(head->right){
                    q.push_back(head->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(layer);
            count++;
        }
        return res;
        
    }

};