class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j  = 0; j < n; ++j) {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                dfs(i, j, visited, grid);
                ++cnt;
            }
        }
        return cnt;
    }

    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == '0')
            return;
        visited[i][j] = true;
        dfs(i + 1, j, visited, grid);
        dfs(i, j + 1, visited, grid);
        dfs(i - 1, j, visited, grid);
        dfs(i, j - 1, visited, grid);
    }
};