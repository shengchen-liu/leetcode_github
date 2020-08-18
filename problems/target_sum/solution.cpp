class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> memo(nums.size());
        return helper(nums, S, 0, memo);
    }
    int helper(vector<int>& nums, long sum, int start, vector<unordered_map<int, int>>& memo) {
        if (start == nums.size()) return sum == 0;
        if (memo[start].count(sum)) return memo[start][sum];
        int cnt1 = helper(nums, sum - nums[start], start + 1, memo);
        int cnt2 = helper(nums, sum + nums[start], start + 1, memo);
        return memo[start][sum] = cnt1 + cnt2;
    }
};