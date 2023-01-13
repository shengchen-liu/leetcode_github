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

/*
dfs: start at cur node, search for all connected nodes
dfs(cur, visited):
    if visited.count(cur)
        return
    newNode
    m[cur] = newNode
    for each neighbor:
        visited.insert(neighbor)
        dfs(neighbor, visited)
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        if (!node)
            return NULL;
        
        Node* newNode = dfs(node, m);
        return newNode;
    }
    
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& m) {
        if (!cur)
            return NULL;
        if (m.find(cur) == m.end()) {
            Node* newCur = new Node(cur->val);
            m[cur] = newCur;
            for (auto neighbor : cur->neighbors) {
                m[cur]->neighbors.push_back(dfs(neighbor, m));
            }
        }

        return m[cur];
    }
};