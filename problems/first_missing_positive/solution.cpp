class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 1. check if 1 is present
        int n = nums.size();
        bool num_1 = false;
        
        for (int num : nums) {
            if (num == 1) {
                num_1 = true;
                break;
            }
        }
        
        if (!num_1) return 1;
        
        // 2. [1]
        if (n == 1) return 2;
        
        // 3. replace non-pos values and values > n  to be 1s
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n ) {
                nums[i] = 1;
            }
        }
        
        // 4. for val = nums[i], set the nums[val] to be negative
        for (int i = 0; i < n; ++i) {
            int val =  abs(nums[i]);
            // check nums[abs(val)]
            
            if (val == n) {
                nums[0] = -abs(nums[0]);
            }
            else {
                nums[val] = -abs(nums[val]);
            }
        }
        
        // 5. find the 1st positive value
        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) return i;
        }
        
        if (nums[0] > 0) return n;
        
        return n + 1;
        
    }
};