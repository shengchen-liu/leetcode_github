/*
1 3 1
1 5 1
4 2 1

1 3
1 5

2 path: 1->3->5; 1->1->5
dp[i][j]: min path sum from (0,0) to (i,j)
dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])

*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Boundary condition
                // (0, 0)
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                
                // 1st row
                else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                
                // 1st col
                else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                
                // general relation
                else {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};