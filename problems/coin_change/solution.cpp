/*
1,2,5
dp[i]: fewest number of coins if amount = i.

for each c in coins:
    dp[i] = min(dp[i - c] + 1, dp[i])
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; ++i) {
            for (int c : coins) {
                if (i >= c) {
                    dp[i] = min(dp[i - c] + 1, dp[i]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};