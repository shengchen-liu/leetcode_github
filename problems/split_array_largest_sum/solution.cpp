/*
7,2,5,10,8, m = 2

dp[i][j]: minimum largest sum for firt i idx (1-based) with j splits
dp[0][0] = ?

      k     i
* * * * | * *
      
dp[i][j] = min{
    dp[k][j-1] + max(nums[k+1 to i])
} k in range [j-1, i-1]
*/



class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        vector<int> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return f[n][m];
    }
};