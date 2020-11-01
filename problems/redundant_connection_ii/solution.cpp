/*
u->v
two cases for the tree struct to be invalid:
1. a node has two parents
2. a circle exists
a single node can have at most two parents
1) check if there is a node that has two parents.
    if true: store these parents as A, B.  and set the second edge invalid
2) union find
    if the tree is now valid:
        return B
    else if candidates not existing:
        we need to find a circle
    else 
        remove candidate A instead of B
*/
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> candA;
        vector<int> candB;
        // 1) check if there is a node that has two parents
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (parent[v] > 0) {
                candA = {parent[v], v};
                candB = edge;
                edge[1] = 0;
            } else {
                parent[v] = u;
            }
        }
        
        // 2). union find
        // 1. initialize parent
        for (int i = 1; i < n + 1; ++i)
            parent[i] = i;
        
        // 2. find
        for (auto &edge : edges) {
            if (edge[1] == 0) continue;
            int u = edge[0];
            int v = edge[1];
            int pu = find(u, parent); // parent of u
            // 3. merge
            if (!merge(u, v, parent)) {
                if (candA.empty()){// every node has only 1 parent
                    // find the circle
                    return edge;
                }
                return candA;
            }   
        }
        return candB;
    }
    
    // return the parent of x
    int find(int x, vector<int> &parent){
        int j, px;
        j = x;
        while (parent[j] != j){
            j = parent[j];
        }
        while (x != j) {
            px = parent[x];
            parent[x] = j;
            x = px;
        }
        return j;
    }
    
    // return true if x, y have different parents
    bool merge(int x, int y, vector<int> &parent) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px == py) return false;
        parent[px] = py;
        return true;
    }
};