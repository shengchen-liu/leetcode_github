/*
n steps
1 or 2 steps
n = 3
1, 1, 1
1, 2
2, 1
dp[i]: num of ways to climb to i steps
dp[i] = dp[i - 1] + dp[i - 2]

initial:
dp[0] = 1
dp[1] = 1
...
dp[2] = dp[0] + dp[1] = 1 + 1=  2
dp[3] = dp[1] + dp[2] = 1 + 2 = 3
*/
class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1);
        // dp[0] = 1;
        // dp[1] = 1;
        if (n == 1) return 1;
        int back2 = 1;
        int back1 = 1;
        int cur = 0;
        for (int i = 2; i < n + 1; ++i) {
            cur =  back2 + back1;
            back2 = back1;
            back1 = cur;
        }
        return cur;
    }
};