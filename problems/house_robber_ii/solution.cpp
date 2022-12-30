/*
use houseRobber1 twice:
houseRobber1 on [1...n-1]
houseRobber1 on [2...n]
compare two res
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int r1 = houseRobber1(nums, 0, n - 2);
        int r2 = houseRobber1(nums, 1, n - 1);
        return max(r1, r2);
    }

    int houseRobber1(vector<int>& nums, int start, int end) {
        int cur = 0;
        int pre = 0;
        for (int i = start; i <= end; ++i) {
            int tmp = cur;
            cur = max(cur, pre + nums[i]);
            pre = tmp;
        }
        return cur;
    }
};