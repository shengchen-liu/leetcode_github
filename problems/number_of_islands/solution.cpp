/*
dfs
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        if (grid.size() == 0)
            return cnt;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                dfs(i, j, grid, visited);
                ++cnt;
            }
        }
        
        return cnt;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        // termination
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j <0 || j >= n || visited[i][j] || grid[i][j] == '0')
            return;
        
        // recursion
        visited[i][j] = true;
        
        // four directions
        dfs(i - 1, j, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
        dfs(i, j + 1, grid, visited);
    }
};