class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // base case
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // base case
                if (i ==0 || j ==0) {
                    if (matrix[i][j] == '1') dp[i][j] = 1;
                    else dp[i][j] = 0;
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};