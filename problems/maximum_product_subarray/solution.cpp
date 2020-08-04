class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        // initial
        int cur_max = nums[0];
        int cur_min = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < n; ++i) {
            int temp_max = max(nums[i], max(nums[i] * cur_max, nums[i] * cur_min));
            cur_min = min(nums[i], min(nums[i] * cur_max, nums[i] * cur_min));
            cur_max = temp_max;
            res = max(res, cur_max);
        }
        
        return res;
        
    }
};