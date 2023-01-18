/*
case 1
regular array: 
dp[i]: max sum for left ith nums, have to use ith num
1) only thi num.  nums[i-1]
2) use previous num.  dp[i - 1] + nums[i - 1]
dp[i] = max(nums[i-1], dp[i-1]+nums[i-1])

case2: the subarary take a part of both sides
convert it to : max res = total sum -  min subarray sum in normal arrary

*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0;
        int curMin = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        for (int num : nums) {
            // case 1
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            // case 2, minSum
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
        }

        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};