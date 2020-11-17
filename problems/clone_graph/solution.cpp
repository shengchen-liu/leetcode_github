/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

1(pt1) -> 2(pt2)
|
4(pt4)

return:
1(pta) -> 2(ptb)
|
4(ptd)

deepcopy:
1. a new node
2. copy value
3. neighbors of new nodes

hashmap: {old node : new node}
oldNode->val
create a newNode(val)
newNode->neighbor = oldNode->neigbor
1(pta) -> 2(pt2)
1(pta) -> 2(ptb)

for each node in newNode's neighbor:
    node = hashmap(node)
    
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        // create new nodes, hashmap
        unordered_map<Node*, Node*> m;
        
        // BFS to find all old nodes
        queue<Node*> q;
        q.push(node);
        unordered_set<Node*> visited;
        visited.insert(node);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            // check its neighbors
            for (Node* neigh : cur->neighbors) {
                if (visited.count(neigh))
                    continue;
                visited.insert(neigh);
                q.push(neigh);
            }
        }
        
        // build new nodes, mapping
        for (Node* a : visited) {
            m[a] = new Node(a->val);
        }
        
        // deep copy neighbors
        for (Node* old : visited) {
            Node* new_node = m[old];
            for (Node* old_neigh : old->neighbors) {
                new_node->neighbors.push_back(m[old_neigh]);
            }
        }
        
        return m[node];
    }
};