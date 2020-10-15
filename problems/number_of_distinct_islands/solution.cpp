/*
dfs
11011
10000
00001
11011

*/
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};

    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<vector<pair<int, int>>> res;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                // dfs
                vector<pair<int, int>> isl;
                dfs(i, j, i, j, grid, isl);
                res.insert(isl);
                
            }
        }
        return res.size();
        
    }
    
    void dfs(int x, int y, int x0, int y0,
             vector<vector<int>>& grid, 
             vector<pair<int, int>>& isl) {
        int m = grid.size();
        int n = grid[0].size(); 
        
        // termination
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
            return;
        
        // recursion
        // curent grid
        isl.push_back({x - x0, y - y0});
        grid[x][y] *= -1;
        
        // 4 neighbors
        for (int i = 0; i < 4; ++i) {
            dfs(x + dirs[i][0], y + dirs[i][1], x0, y0, grid, isl);
        }
    }
};