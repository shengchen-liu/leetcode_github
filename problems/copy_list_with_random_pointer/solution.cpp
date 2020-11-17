/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

1.creat new nodes
hashmap : {old : new}

2. for each old node:
    new_nodes = hashmap[old]
    new_nodes->next = hashmap[old->next]
    new_nodes->random = hashmap[old->random]
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> m;
        // create new nodes
        Node* old = head;
        while (old) {
            m[old] = new Node(old->val);
            old = old->next;
        }
        
        // for each old node
        old = head;
        while (old) {
            Node* new_node = m[old];
            new_node->next = m[old->next];
            new_node->random = m[old->random];
            old = old->next;
        }
        return m[head];
    }
};