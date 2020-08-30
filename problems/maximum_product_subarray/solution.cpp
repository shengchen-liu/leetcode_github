class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int max_so_far = 1;
        int min_so_far = 1;

        for (int i = 1; i <= n; ++i) {
            int cur = nums[i - 1];
            // max_dp[i] = max(nums[i - 1], max(max_dp[i - 1] * nums[i - 1],
            //                                 min_dp[i - 1] * nums[i - 1]));
            // min_dp[i] = min(nums[i - 1], min(max_dp[i - 1] * nums[i - 1],
            //                                 min_dp[i - 1] * nums[i - 1]));
            int temp_max = max(cur, max(max_so_far * cur, min_so_far * cur));
            min_so_far = min(cur, min(max_so_far * cur, min_so_far * cur));
            
            max_so_far = temp_max;
            res = max(max_so_far, res);
        }
        
        
        return res;
    }
};