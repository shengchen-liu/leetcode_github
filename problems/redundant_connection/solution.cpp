/*
u.par == v.par?
    true: return {u, v}
    false: update union with {u, v}
    
    1, 2, 3, 4, 5
par 1, 2, 3, 4, 5  edge:[1, 2].  1.par != 2.par? 
    1, 1, 3, 4, 5  edge:[2, 3].  2.par != 3.par
    1, 1, 1, 4, 5  edge:[3, 4].  3.par(1) != 4.par(4)
    1, 1, 1, 1, 5  edge:[1, 4].  1.par(1) = 4.par(1) => return {1, 4}    
    

*/
class Union{
public:
    Union(int n) {
        parents.resize(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            parents[i] = i;
        }
    }
    
    int find(int x) {
        int j, px;
        j = x;
        while (parents[j] != j) {
            j = parents[j];
        }
        while (x != j){
            px = parents[x];
            parents[x] = j;
            x = px;
        }
        return j;
    }
    
    // if x, y have different parents, merge two union sets that include x, y
    // return true if merged, return false if x, y have same parent
    bool merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        
        parents[px] = py;
        return true;
    }    
    
private:
    vector<int> parents;
    
};


class Solution {
public:
    //
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // initialize union
        Union u(edges.size());
        
        // merge
        for (auto edge : edges) {
            if (!u.merge(edge[0], edge[1]))
                return edge;
        }
        return {};
    }

};