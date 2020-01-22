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
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // copy next
        if (!head) return head;
        
        Node* curr = head;
        Node* temp;
        while (curr){
            Node* new_curr = new Node(curr->val);
            temp = curr->next;
            curr->next = new_curr;
            new_curr->next = temp;
            curr = temp;
        }
        
        curr = head;
        while (curr){
            if (curr->random){ // if random is not pointing to null
                curr->next->random = curr->random->next;
            }
            else{
                curr->next->random = NULL;
            }
            curr = curr->next->next;
        }
        
        // break old links
        curr = head;
        Node* new_header = head->next;
        while (curr){
            Node* new_curr = curr->next;
            curr->next = new_curr->next;
            if (new_curr->next){
                new_curr->next = new_curr->next->next;
            }
            curr = curr->next;
        }
        return new_header;
        
    }
};