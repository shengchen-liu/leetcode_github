/*
dp[i]: longest increasing subsequence of first i elems
dp size of n + 1
dp[0] = 0
dp[i]: vs dp[i-1]

for i from 0 to n-1:
    for j from 0 to i-1:
        if num[i] > num[j]:
            dp[i] = max(dp[j]) + 1

return max(dp[i])

*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }
};