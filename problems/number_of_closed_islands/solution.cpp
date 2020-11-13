/*
dfs
closed islands:
 11
1001
 11
for each ele in grid:
    if ele == 0 and not visited:
        if dfs(ele, visited) is true:
            ++cnt

helper function: start from given ele, find all connected closed grid. 
return true=> if it can construct a closed islands
retrur false=> otherwise

bool dfs(ele, visited):
    visited[ele] = true
    
    if ele is on edges:
        return false;
    // top, bottom, left, right
    if top == 0 and !visited[top] and !dfs(top, visited): return false
    if bottom == 0 and !visited[bottom] and !dfs(bottom, visited): return false
    if left == 0 and !visited[left] and !dfs(left, visited): return false
    if right == 0 and !visited[right] and !dfs(right, visited): return false
    
    return true
    
    
*/
class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j,  vector<vector<bool>> &visited) {
        int m = grid.size();
        int n = grid[0].size();
        // termination
        if (i < 0 || i >= m  || j < 0 || j >= n ) return false;
        
        // recursion
        if (grid[i][j] == 1 || visited[i][j]) return true;
        
        visited[i][j] = true;
        // neighbors
        // top
        bool d1 = dfs(grid, i+1, j, visited);
        bool d2 = dfs(grid, i, j+1, visited);
        bool d3 = dfs(grid, i-1, j, visited);
        bool d4 = dfs(grid, i, j-1, visited);
        // cout << i << j << endl;
        return d1 && d2 && d3 && d4;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // each element
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) continue;
                // call dfs
                if (!visited[i][j] && dfs(grid, i, j, visited))
                    ++cnt;
            }
        }
        return cnt;
    }
};