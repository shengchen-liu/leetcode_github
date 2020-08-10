class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        int res = 0;
        if (k > n / 2) {
            for (int i = 1; i < prices.size(); ++i)
            {
                if (prices[i] - prices[i - 1] > 0)
                {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }
        // corner case
        if (n == 0){
            return 0;
        }
        // main part
        vector<vector<int>> dp(k + 1, vector<int>(n));
        for (int i = 1; i < dp.size(); i ++){
            int maxDiff = -prices[0];
            for (int j = 1; j < dp[0].size(); j ++){
                maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j]);
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            }
        }
        return dp[k][n - 1];
    }
};