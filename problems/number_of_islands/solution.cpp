// dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                helper(grid, visited, i, j, m, n);
                ++res;
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>>& grid, 
                vector<vector<bool>>& visited, 
               int x,
               int y,
                int m, 
                int n) {
        if (x < 0 || x >= m || y < 0 || y >= n || 
            visited[x][y] || grid[x][y] == '0') return;
        visited[x][y] = true;
        helper(grid, visited, x - 1, y, m, n);
        helper(grid, visited, x + 1, y, m, n);
        helper(grid, visited, x, y - 1, m, n);
        helper(grid, visited, x, y + 1, m, n);
    }
};