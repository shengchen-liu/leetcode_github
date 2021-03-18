/*
1,2,3,4 -> 1,2,4,3
1,3,2,4 -> 1,3,4,2
1,4,2,3 -> 1,4,3,2
1,4,3,2 -> 2,1,3,4

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        
        // now is the number to swap
        // find the num to swap with, nums[j] is the next largest number than nums[i]
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i])
                --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};