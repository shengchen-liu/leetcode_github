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
*/


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return {};
        // 1. get all nodes in visited
        // BFS
        queue<Node*> q;
        q.push(node);
        unordered_set<Node*> visited;
        visited.insert(node);
        
        while (!q.empty()) {
            Node *oldNode = q.front();
            q.pop();
            // neighbors
            for (auto neighbor : oldNode->neighbors) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        // 2. copy all original nodes to a new nodes set: mapping(n : new Node(n))
        unordered_map<Node*, Node*> mapping;
        for (Node* i : visited) {
            mapping[i] = new Node(i->val);
        }
        
        // 3. copy all neighbors
        for (auto old_node : visited) {
            auto new_node = mapping[old_node];
            for (auto neighbor : old_node->neighbors) {
                new_node->neighbors.push_back(mapping[neighbor]);
            }
        }
        return mapping[node];
    }
};