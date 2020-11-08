/*
int n
nums, size : n + 1
num[0], nums[1]
nums[2*i], nums[2*1 + 1]
n=7
j  nums[j]
0  0
1  1
2  1
3  2
4  1
5  3
6  2
7  3

max: 3

observation: j
case1: j is even = 2 * i
case2: j is odd number = 2 * i + j

*/
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<int> dp(n + 1, 0);
        int res = 1;
        
        // initial
        dp[0] = 0;
        dp[1] = 1;
        
        // iteration
        for (int j = 2; j <= n; ++j) {
            // check even or odd
            // 1. even
            if (j % 2 == 0) {
                dp[j] = dp[j / 2];
            } else {
                // 2. odd
                int i = j / 2;
                dp[j] = dp[i] + dp[i + 1];
            }
            res = max(res, dp[j]);
        }
        
        return res;
    }
};