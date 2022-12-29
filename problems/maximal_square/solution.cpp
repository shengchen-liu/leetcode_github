/*
dp[i][j]: start from (i, j) as bottom right corner, max square area
dp[0][0] = 0 if matrix[i][j] == 0 
         = 1  if matrix[0][0] == 0

dp[i][j] vs dp[i-1][j-1]:
    if matrix[i][j] == 0 : dp[i][j] = 0
    else:
        if matrix[i][j-1] == 1 and matrix[i-1][j] == 1: dp[i][j] = dp[i-1][j-1] + 1
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};