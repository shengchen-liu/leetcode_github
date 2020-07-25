class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {0};
        if (k == 1) return nums;
        
        vector<int> left(n); // the largest element from 0 to i
        vector<int> right(n); // the largest element from n - 1 to i
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        
        // divied into several blocks
        for (int i = 1; i < n; ++i) {
            // from left to right
            if (i % k == 0) left[i] = nums[i]; // block start
            else left[i] = max(left[i - 1], nums[i]);
            
            // from right to left
            int j = n - i - 1;
            if ((j + 1) % k == 0) right[j] = nums[j]; // block end
            else right[j] = max(right[j + 1], nums[j]);
        }
        
        vector<int> res(n - k + 1);
        for (int i = 0; i < n - k + 1; ++i) 
            res[i] = max(left[i + k - 1], right[i]);
        
        return res;
    }
};