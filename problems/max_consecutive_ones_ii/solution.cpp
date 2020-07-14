class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        int k = 1;
        int cnt = 0; // no. of zeros
        
        for (right = 0; right < n; ++right) {
            if (nums[right] == 0) ++cnt;
            while (cnt > k) {
                if (nums[left] == 0) --cnt;
                ++left;
            }
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};