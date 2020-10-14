/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
dfs
1. res push current node
2. res push '['
3. for each child:
    f(child)
4. res push ']'

*/
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serialize(root, res);
        return res;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
    
    // dfs 
    void serialize(Node* node, string& res) {
        // termination: node is null
        if (!node) {
            res += "#";
            return;
        }
        
        // recursion
        res += to_string(node->val) + " " + to_string(node->children.size()) + " ";
        
        // check if node has children
        if (node->children.size() == 0)
            return;
        
        // children
        for (auto child : node->children) {
            serialize(child, res);   
        }
        
    } 
    
    Node* deserialize(istringstream &iss) {
        string tmp;
        string size;
        iss >> tmp;
        
        // termination
        if (tmp == "#") return NULL;
        
        iss >> size;
        // recursion
        Node *node = new Node(stoi(tmp), {});
        for (int i = 0; i < stoi(size); ++i) {
            node->children.push_back(deserialize(iss));
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));