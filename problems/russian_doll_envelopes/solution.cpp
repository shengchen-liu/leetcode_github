class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        int res = 0;
        vector<int> dp (envelopes.size(), 1);
        // 1. sort by w
        sort(envelopes.begin(), envelopes.end());
        
        // 2. dp[i] = dp[j] + 1
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // check w, h
                if (envelopes[i][0] == envelopes[j][0] || 
                    envelopes[i][1] <= envelopes[j][1]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        // find max in dp
        for (auto a : dp) {
            if (a > res) res = a;
        }
        
        return res;
    }
};