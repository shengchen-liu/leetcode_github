class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        for (int i = 0; i < n; ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}}; // node i's neighbor
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                for (auto a : graph[t]) {
                    if (colors[a] == colors[t]) return false;
                    if (colors[a] == 0) {
                        colors[a] = -1 * colors[t];
                        q.push(a);
                    }
                }
            }
        }
        return true;
    }
};