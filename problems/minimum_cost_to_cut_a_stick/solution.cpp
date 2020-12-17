class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int k = cuts.size();
        vector<vector<int>> dp(k, vector<int>(k, 0));
        
        // for each length from 2 to k
        for (int d = 2; d < k; ++d) {
            // start idx from 0 to k - d
            for (int i = 0; i < k - d; ++i) {
                dp[i][i + d] = INT_MAX;
                for (int m = i + 1; m < i + d; ++m) {
                    dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + (cuts[i + d] - cuts[i]));
                }
            }
        }
        return dp[0][k - 1];
    }
};