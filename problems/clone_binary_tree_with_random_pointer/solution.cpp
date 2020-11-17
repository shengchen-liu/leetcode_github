/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> m;
        if (!root) return NULL;
        
        // recursion 1
        NodeCopy* res = dfs1(root, m);

        return res;
        
    }
    
    // recursion1
    NodeCopy* dfs1(Node* old_node, unordered_map<Node*, NodeCopy*>& m) {
        // termination
        if (!old_node) 
            return NULL;
        
        if (m.count(old_node)) 
            return m[old_node];
        
        // recursion
        NodeCopy* new_node = new NodeCopy();
        new_node->val = old_node->val;
        m[old_node] = new_node;
        // left, right
        
        new_node->left = dfs1(old_node->left, m);
        new_node->right = dfs1(old_node->right, m);
        new_node->random = dfs1(old_node->random, m);
        return new_node;
    }
    
};