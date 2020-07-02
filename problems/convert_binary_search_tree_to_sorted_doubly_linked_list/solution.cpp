/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

/*
  node ->left = predecessor
  node ->right = successor
*/
class Solution {
public:
    // the smallest (first) and the largest (last) nodes
    Node * first = NULL;
    Node * last = NULL;
    
    void helper(Node* node) {
        if (node) {
            helper(node->left);
            if (last) {
                last->right = node;
                node->left = last;
            } else {
                first = node;
            }
            last = node;
            // right
            helper(node->right);
        }
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        helper(root);
        // close DLL
        last->right = first;
        first->left = last;
        return first;
    }
};