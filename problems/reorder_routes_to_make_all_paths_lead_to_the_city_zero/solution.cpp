/*
map from -> to
1:0
1:2
3:2
3:4

map to->from
0:1
2:1
2:3
4:3

0<-1->2<-3->4
{0, 1}
0<-1 no change, # of changes: 0
{0, 1, 2}
dp[i][j]: min # of changes for nodes i ~ j. those nodes can reach to node 0
dp[0][0] :=0
dp[1][1] :=0
dp[2][2] := 1 + min{re[1, 2], re[3, 2]}
*/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // build a graph
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto a : connections) {
            int from = a[0];
            int to = a[1];
            graph[from].push_back({to, 1});
            graph[to].push_back({from, 0});
        }
        
        // dfs
        unordered_set<int> visited;
        int res = helper(0, visited, graph);
        return res;
    }
    
    // return # of changes starting from current node
    int helper(int node, 
               unordered_set<int>& visited, 
               unordered_map<int, vector<pair<int, int>>>& graph) {
        // termination
        if (visited.count(node)) return 0;
        
        // recursion
        visited.insert(node);
        
        // check node's neighbors
        int sum = 0;
        for (auto n : graph[node]) {
            if (visited.count(n.first)) continue;
            if (n.second == 1)
                ++sum;
            sum += helper(n.first, visited, graph);
        }
        
        return sum;
    }
};