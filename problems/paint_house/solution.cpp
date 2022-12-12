class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
        for (int i = 0; i < 3; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <=n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = costs[i - 1][j];
                if (j == 0) dp[i][j] += min(dp[i - 1][1], dp[i - 1][2]);
                else if (j == 1)  dp[i][j] += min(dp[i - 1][0], dp[i - 1][2]);
                else  dp[i][j] += min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        int res = min(min(dp[n][0], dp[n][1]), dp[n][2]);
        return res;
    }

};