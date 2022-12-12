class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++res;
                dfs(graph, visited, i);
            }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int i) {
        if (visited[i]) return;
        visited[i] = true;
        vector<int> neighbors = graph[i];
        for (int j : neighbors) {
            dfs(graph, visited, j);
        }
    }
};