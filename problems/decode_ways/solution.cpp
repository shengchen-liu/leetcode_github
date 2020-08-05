class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1);
        // int num = (s[0] - '0') + (s[1] - '0'); 
        dp[0] = 1;
        dp[1] = (s[0] - '0' > 0) ? 1 : 0;
        
        for (int i = 2; i <= n; ++i) {
            // i'th element in s => s[i - 1]
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num <= 26 && num >= 10) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};