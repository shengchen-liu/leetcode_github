/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        // 1. get all original nodes -> unordered_set(n1,n2,n3,n4)
        unordered_set<Node*> original_nodes = getNodes(node);
        
        // 2. copy all original nodes to a new nodes set : mapping(n: new Node(n))
        unordered_map<Node*, Node*> mapping;
        for (Node* i : original_nodes){
            // cout << i -> val <<endl;
            mapping[i] = new Node(i -> val);
        }
        
        // 3. copy all neighbors into the new mapping
        for (Node* old_node : original_nodes){
            Node* new_node = mapping[old_node];
            for (Node* neighbor : old_node -> neighbors){
                // cout << neighbor -> val <<endl;
                // be careful, this is old neighbor.  Should use mapping to find the address of the new neighboer
                new_node -> neighbors.push_back(mapping[neighbor]);
            }
        }
        return mapping[node];
    }
    
    unordered_set<Node*> getNodes(Node* node){
        //queue
        queue<Node*> que;
        que.push(node);
        //set ()
        unordered_set<Node*> all_nodes;
        all_nodes.insert(node); // (1)
        
        // BFS
        while(!que.empty()){
            Node* head = que.front();
            que.pop();  // head: 1
            // loop through all neighbors
            int size = (head -> neighbors).size();
            for (int i = 0; i < size; i++){ //
                Node* neighbor = head -> neighbors[i]; //neighbor: 2
                if(!all_nodes.count(neighbor)){
                    all_nodes.insert(neighbor);
                    que.push(neighbor);
                    // cout << neighbor -> val << endl;
                }
            }
        }
        return all_nodes;
        
    }
};