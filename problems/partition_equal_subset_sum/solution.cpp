/*
dp[i][j]: wheterh we can sum to j using first i numbers

dp[i][j] = true if dp[i-1][j - nums[i]]
return dp[n][target]
initial:
dp[0][0] = true
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // even, odd
        if (total_sum % 2 != 0)
            return false;
        
        int target = total_sum / 2;
        // vector<vector<bool>> dp(n + 1, vector<bool> (target + 1, false));
        // // initial condition
        // dp[0][0] = true;
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for (int cur : nums){
            for(int j = target; j >= cur; --j){
                dp[j] = dp[j] || dp[j - cur];
            }
        }
        return dp[target];
        
    }
};