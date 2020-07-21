class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int j = i - 2 - dp[i - 1];
            if (s[i - 1] == '(' || j < 0 || s[j] == ')') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i - 1] + 2 + dp[j];
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};