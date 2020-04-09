/**
4,7,9,10
K = 3
4, 5, 6, 8

4: 2
**/
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > missing(n - 1, nums)) {
            return nums[n - 1] + k - missing(n - 1, nums);
        }
        
        int left = 0, right = n - 1, pivot;
        while (left != right) {
            pivot =  left + (right - left) / 2;
            
            if (missing(pivot, nums) < k) left = pivot + 1;
            else right = pivot;
        }
        
        return  nums[left - 1] + k - missing(left - 1, nums);
    }
    
    int missing(int idx, vector<int>& nums) {
        return nums[idx] - nums[0] - idx;
    }
};