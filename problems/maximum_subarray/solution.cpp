/*
                        
-2, 1,  -3,4,-1,2,1,-5,4   res   max_sum
i                          []    0
   i,j                    [1]   1
    i   j  
    i      j
   

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > 0)
                nums[i] += nums[i - 1];
            maxSum = max(nums[i], maxSum);
        }
        return maxSum;
    }
};