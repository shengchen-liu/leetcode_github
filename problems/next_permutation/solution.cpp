/*
6 2 1 5 4 3 0
    i
    
6 2 3 5 4 1 0
    i
reverse 
6 2 3 0 1 4 5

from right to left, check if the sub combinatinon is decreasing order
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2; 
        while (i >= 0 && nums[i + 1] <= nums[i])
            --i;
        
        // now i is the num to swap
        // find the num to swap with, which is the next largest number than nums[i]
        if (i >= 0){
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i])
                --j;
            swap(nums[i], nums[j]);
        }
        
        // now from i + 1 to n-1 is a decreasing order.  we need to reverse it 
        reverse(nums.begin() + i + 1, nums.end());
    }
};