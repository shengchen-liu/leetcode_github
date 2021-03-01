/*
1, 1, 1, 1, 1
S: 3
dp[i][j]: num of ways to assign first i integers, sum up to j

*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (S > sum || sum < -S)
            return 0;
        if ((S + sum) & 1) 
            return 0;
        int target = (S + sum) / 2;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = target; j >= nums[i-1]; --j) {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};