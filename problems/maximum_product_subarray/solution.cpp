/*
[2,3,-2,4]
2, 3, -2, 4

location i: largest subarray that ends at nums[i]
1) subarray don't contain arrays in front : nums[i]
2) nums[i] * dp[i-1]
max of 1) 2)
dp[i] = max(nums[i], nums[i] * dp[i - 1])
dp[0] = nums[0]
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_sofar = nums[0];
        int min_sofar = nums[0];
        int res = INT_MIN;
        if (n == 1)
            return max_sofar;
        for (int i = 1; i < n; ++i) {
            int tmp_max = max(nums[i], max(nums[i] * max_sofar, nums[i] * min_sofar));
            min_sofar = min(nums[i], min(nums[i] * max_sofar, nums[i] * min_sofar));
            max_sofar = tmp_max;
            res = max(res, max_sofar);
        }
        return max(nums[0], res);
    }
};