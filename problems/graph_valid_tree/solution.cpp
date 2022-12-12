class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<bool> visited(n, false);
        for (auto a : edges) {
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        if (!dfs(g, visited, 0, -1)) return false;
        for (auto a : visited) {
            if (!a) return false;
        }
        return true;

    }

    bool dfs(vector<vector<int>>& g, vector<bool>& visited, int cur, int pre) {
        if (visited[cur]) return false;
        visited[cur] = true;
        for (auto a : g[cur]) {
            if (a != pre) {
                if (!dfs(g, visited, a, cur))
                    return false;
            }
        }
        return true;
    }
};