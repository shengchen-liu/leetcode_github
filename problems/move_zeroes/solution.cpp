/**
[0,1,0,3,12]

**/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;
        int i = 0;
        int j = 0;
        while (j < n) {
            if (nums[j]) {
                swap(nums[i++], nums[j]);
            }
            ++j;
        }
        
    }
};