class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);  // min path sum from (0,0) to jth column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Boundary condition
                // (0, 0)
                if (i == 0 && j == 0) {
                    dp[j] = grid[i][j];
                }
                
                // 1st row
                else if (i == 0) {
                    dp[j] = dp[j - 1] + grid[i][j];
                }
                
                // 1st col
                else if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                }
                
                // general relation
                else {
                    dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
                }
            }
        }
        return dp[n-1];
    }
};