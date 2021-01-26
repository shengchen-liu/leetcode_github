/*
pivot index
1,7,3,6,5,6
total_sum = 11 + 11 + 6 = 28
left_sum | pivot_val | right_sum
left_sum = total_sum - pivot_val

prefix_sum
1, 7, 3, 6, 5, 6
1  8  11 17 22 28

-1 1 -1
p
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return -1;
        int total_sum = 0;
        int left_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        for (int i = 0; i < n; ++i) {
            if (left_sum == total_sum - nums[i] - left_sum) 
                return i;
            left_sum += nums[i];
        }
        return -1;
    }
};