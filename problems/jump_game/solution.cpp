class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0); // 当前位置剩余的跳力
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) -1;
            if (dp[i] < 0) return false;
        }
        return true;
    }
};