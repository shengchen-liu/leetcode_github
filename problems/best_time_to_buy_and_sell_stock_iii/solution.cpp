class Solution {
public:
    int maxProfit(vector<int>& prices) {
                int n = prices.size();
        int K = 2;
        // corner case
        if (n == 0){
            return 0;
        }
        // main part
        vector<vector<int>> dp(K + 1, vector<int>(n));
        for (int i = 1; i < dp.size(); i ++){
            int maxDiff = -prices[0];
            for (int j = 1; j < dp[0].size(); j ++){
                maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j]);
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            }
        }
        return dp[K][n - 1];
    }
};