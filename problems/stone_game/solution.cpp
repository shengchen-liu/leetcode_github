class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][j]: max(your stone - opp stone) for piles i to i + l - 1
        vector<int> dp(piles);
        for (int l = 2; l <= n; ++l) { // length of the sub range
            for (int i = 0; i < n - l + 1; ++i) {
                dp[i] = max(piles[i] - dp[i + 1], piles[i + l - 1] - dp[i]);
            }
        }
        
        return dp[0]> 0;
    }
};