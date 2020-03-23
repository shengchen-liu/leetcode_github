class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mn = min(mn, nums[j]);
            if (mn == nums[j]) continue;
            for (int k = n - 1; k > j; --k) {
                if (mn < nums[k] && nums[j] > nums[k]) return true;
            }
        }
        return false;
    }
};