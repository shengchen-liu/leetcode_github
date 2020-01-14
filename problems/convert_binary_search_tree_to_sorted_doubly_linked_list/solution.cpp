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
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node* pre = NULL;
        Node* head = NULL;
        inorder(root, pre, head);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void inorder(Node* node, Node*& pre, Node*& head){
        if (!node) return;
        // left
        inorder(node->left, pre, head);
        // node
        if (!head){
            head = node;
            pre = node;
        } else{
            pre->right = node;
            node->left = pre;
            pre = node;
        }
        //right
        inorder(node->right, pre, head);
    }
};