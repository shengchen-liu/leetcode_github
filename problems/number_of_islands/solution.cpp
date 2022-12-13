class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                dfs(grid, i, j, visited);
                ++cnt;
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>> &visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || x > m - 1 || y < 0 || y > n - 1 || visited[x][y] || grid[x][y] == '0')
            return;
        visited[x][y] = true;
        dfs(grid, x + 1, y, visited);
        dfs(grid, x - 1, y, visited);
        dfs(grid, x, y + 1, visited);
        dfs(grid, x, y - 1, visited);
    }
};