/*
012345
010110
 i

1 : flip   noflip
0001

dp[i]: min number of flips to substring s[0 ... i] monotone
dp[0] = 0
dp[i] = dp[i-1] if s[i-1] == '1'
dp[i] = min(dp[i-1]+1, num) if s[i-1] = '0
num: num of 1's in prefix
*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        int num = 0;
        for (int i = 1; i <= n; ++i) {
            char c = s[i - 1];
            if (c == '0'){
                dp[i] = min(dp[i - 1] + 1, num);
            } else {
                dp[i] = dp[i - 1];
                ++num;
            }
        }
        return dp[n];
    }
};