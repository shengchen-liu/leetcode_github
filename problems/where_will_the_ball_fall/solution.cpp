/*
2d gird mxn
box: 
\ : 1
/ : -1
stuck: 
    1. "v" shape
    2. hits wall

start from row 0, simulate if the ball can reach to the last row

for grid[i][j], check the final destination starting fomr [i,j]

memorization:
visited: mxn, initial 0

dfs(int i, int j):
    // termination
    i  == m:
        return j
    // recurse
    if (visited[i][j] != 0)
        return visited[i][j]
        
    cur = grid[i][j]  // 1, or -1
    // determine the next stop
    // check if the ball is stuck
    if stuck : 
        return -1
    update visited = dfs(i + 1. j + cur)
    return visited[i][j]
    
*/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> res(n, 0);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        // traverse each col
        for (int j = 0; j < n; ++j) {
            res[j] = dfs(0, j, grid, visited);
        }
        
        return res;
    }
    
    // dfs
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &visited){
        int m = grid.size();
        int n = grid[0].size();
        // termination
        if (i == m)
            return j;
        
        // recursion
        if (visited[i][j] != 0) {
            return visited[i][j];
        }
        
        // cur dir
        int cur = grid[i][j];
        
        // check stuck?
        // cur = 1  \ /
        if (cur == 1 && (j == n - 1 || grid[i][j + 1] == -1)){
            visited[i][j] = -1;
            return -1;
        }
        // cur = -1 \ /
        if (cur == -1 && (j == 0 || grid[i][j - 1] == 1)){
            visited[i][j] = -1;
            return -1;
        }
        
        int next =  j + cur;
        visited[i][j] =  dfs(i + 1, next, grid, visited);
        return visited[i][j];
    }
};