/*
1 2 3
visited : bitmask   
1,2,3 : 1110
state: {node, visited}
BFS
*/


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int kAns = (1 << n) - 1;  // 11111...1
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(1 << n));
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
        }
        
        int steps = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                q.pop();
                int node = p.first;
                int state = p.second;
                // all visited?
                if (state == kAns)
                    return steps;
                if (visited[node][state] == 1)
                    continue;
                visited[node][state] = 1;
                for (int neigh : graph[node]) {
                    q.push({neigh, state | (1 << neigh)});
                }
            }
            ++steps;
        }
        return -1;
        
    }
};