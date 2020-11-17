/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* node) {
        // dfs
        // termination
        if (!node) return NULL;
        
        // recursion
        Node* new_node = new Node(node->val);
        for (auto child : node->children) {
            new_node->children.push_back(cloneTree(child));
        }
        return new_node;
    }
};