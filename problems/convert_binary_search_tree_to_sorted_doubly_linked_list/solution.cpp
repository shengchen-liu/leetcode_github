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
 inOrder(Node):
    if (!node)
        return
    inOrder(node->left)
    if (pred)
        node->left = pred
        pred->right = node
    else:
        pred = node
        first = node

    inOrder(node->right)
        

*/

class Solution {
public:
    Node* first = NULL;
    Node* last = NULL;
    Node* pre = NULL;

    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        inOrder(root);
        first->left = last;
        last->right = first;    
        return first;
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        if (pre) {
            node->left = pre;
            pre->right = node;
        } else {
            first = node;
        }
        pre = node;
        last = node;
        inOrder(node->right);
    }
};