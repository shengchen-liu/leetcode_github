/*
0  1 0 0 0
0* 0 1 0 0
0  0 0 1 0

DFS
traverse all paths from start -> target
for each path, update min # of side jumps
memorizatrio

2d dp

dfs: start from row "r", point "p". return min # of side jumps
*/
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n + 1, -1));
        int res = dfs(obstacles, 2, 0, dp);
        return res;
    }
    
//     dfs
    int dfs(vector<int>& obstacles, int r, int p,  vector<vector<int>>& dp) {
        // termination
        // 1. reach to the end
        if (p == obstacles.size() - 1)
            return 0;
        // 2. reach to an obstacle
        if (r == obstacles[p]) {
            return 1e6;
        }
        // 3. memorization
        if (dp[r][p] != -1)
            return dp[r][p];
        
        // recursion
        // 1. forward is not an obstacle
        if (obstacles[p + 1] != r) {
            dp[r][p] = dfs(obstacles, r, p + 1, dp); 
        } else {
        // 2. forard is an obstacle
            // (r + 1) % 3
            // (r + 2) % 3
            dp[r][p] = 1 + min(dfs(obstacles, ((r + 1) % 3 == 0) ? 3 :(r + 1) % 3, p, dp),
                              dfs(obstacles,  ((r + 2) % 3 == 0) ? 3 :(r + 2) % 3, p, dp));
        }
        return dp[r][p];
    }
};