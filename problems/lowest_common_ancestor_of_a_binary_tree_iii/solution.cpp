/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> path = find_path(p);
        while (q->parent) {
            for (Node* node : path) {
                if (node == q)
                    return q;
            }
            q = q->parent;
        }
        return q;
    }
    
    vector<Node*> find_path(Node *p) {
        vector<Node*> path;
        while (p->parent) {
            path.push_back(p);
            p = p->parent;
        }
        return path;
    }
};