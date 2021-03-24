/*
1,2,5
amount = 5
                   []5
         [1]4          [2]3  [5]0
  [1]3   [2]2  [5] 1       
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n + 1, vector<int> (amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= coins.size(); ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i -1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][amount];
    }
};