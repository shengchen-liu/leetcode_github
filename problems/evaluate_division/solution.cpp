/*
equations: {A_i, B_i}
values: v_i = A_i / B_i (double)
queries:
    queries[j] = [C_j, D_j]: jth query where find answer for C_j / D_j = ?

equations = [["a","b"],["b","c"]]
values = [2.0,3.0]
queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]

build a hashmap
A_i : pair<B_i, V_i>

a / b = 2.0 => a: = {b, 2.0}, {d, 4.0}
b / c = 3.0 => b: = {c, 2.0}

a / c = ? => 6.0
represent a with c

ratio = 1
X = a
//  check if we can find a connection between X, Y
// DFS
bool f(X, Y, &ratio): X =  Y * ratio
    if X == Y:
        return true
    
    for each candidate cand:
        cur_ratio = cand.second; // ratio: 2.0
        cur_X = cand.first // X: b
        if f(cur_X, Y, ratio * cur_ratio):
           return true
           
    return false

b / a = ? => 0.5
a / e = ? => -1.0
a / a = ? => 1.0
x / x = ? => -1.0

*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = queries.size();
        vector<double> res (n, -1);
        
        // build a hashmap
        unordered_map<string, vector<pair<string, double>>> m; //A_i : {B_i, V_i}
        for (int i = 0; i < equations.size(); ++i) {
            // equations, values
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            m[A].push_back({B, val});
            m[B].push_back({A, 1 / val});
        }
        
        // dfs f(X, Y, &ratio)
        for (int i = 0; i < n; ++i) {
            // visited
            unordered_set<string> visited;
            double ratio = 1;
            double final_ratio = 1;
            string X = queries[i][0];
            string Y = queries[i][1];
            if (!m.count(X))
                continue;
            if (dfs(X, Y, ratio, visited, m, final_ratio))
                res[i] = final_ratio;
        }
        
        return res;
    }
    
    bool dfs(string X, string Y, double ratio, 
             unordered_set<string> &visited, 
             unordered_map<string, vector<pair<string, double>>> &m,
             double &final_ratio) {
        // termination
        if (visited.count(X))
            return false;
        if (X == Y) {
            final_ratio = ratio;
            return true;
        }
        
        // recursion
        visited.insert(X);
        for (auto cand : m[X]) { // {string, double}
            string cur_X = cand.first;
            double cur_ratio = cand.second;
            if (dfs(cur_X, Y, ratio * cur_ratio, visited, m, final_ratio))
                return true;
        }
        return false;
    }
};