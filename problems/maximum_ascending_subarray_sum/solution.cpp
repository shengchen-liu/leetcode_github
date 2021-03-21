class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int curSum = 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        
        for (int i = 0; i < n - 1; ++i) {
            curSum += nums[i];
            if (nums[i] >= nums[i + 1]) {
                res = max(res, curSum);
                curSum = 0;
            }
        }
        if (nums[n - 2] < nums[n - 1]) {
            curSum += nums[n - 1];
        } else {
            curSum = nums[n - 1];
        }
        res = max(res, curSum);

        return res;
    }
};