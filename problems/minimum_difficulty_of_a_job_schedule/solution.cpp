/*
6,5,4,3,2,1, d=2

cut the array into d non-empty sub arrays
d1 = [], d2 = []
6 _ 5 _ 4 _ 3 _ 2 _ 1 insert d-1 seperators.  try all possible cuts
6 | 5 _ 4 _ 3 _ 2 _ 1
6 _ 5 | 4 _ 3 _ 2 _ 1
6 _ 5 _ 4 | 3 _ 2 _ 1
6 _ 5 _ 4 _ 3 | 2 _ 1
6 _ 5 _ 4 _ 3 _ 2 | 1

dp[i][j]: i: min difficulty to schedlue the first i jobs (1-based) in k days

init:
    dp[0][0] = 0, others: INT_MAX
transition:
    dp[i][k] = min{
        dp[j][k-1] + max(jobs[j+1 ~ i])
    } for k -1 <= j < i

*/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n) 
            return -1;
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX/2));
        
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= d; ++k) {
                int md = 0;
                for (int j = i - 1; j >= k - 1; --j) {
                    md = max(md, jobDifficulty[j]);
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + md);
                }
            }
        }
        return dp[n][d];
    }
};