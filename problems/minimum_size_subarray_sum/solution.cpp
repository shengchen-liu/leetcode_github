class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int len = INT_MAX;
        int n = nums.size();
        int sum = 0;
        while (r < n) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};