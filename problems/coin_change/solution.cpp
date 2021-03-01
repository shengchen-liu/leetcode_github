/*
coins: 1, 2, 5
amount: 11
11 = 5 + 5 + 1
fewest number of coins
dp[i]: fewest num of coins to sum up to i
for each coin in coins:
    dp[i] = min(dp[i - coin] + 1, dp[i])

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }   
            } 
        }
        return dp[amount] > amount ? -1 : dp[amount];

    }
};