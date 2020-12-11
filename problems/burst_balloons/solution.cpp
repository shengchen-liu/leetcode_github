class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n = nums.size();
        // dp[i][j] 表示 i, j 之間不包含 i, j 可得的最大分數
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};