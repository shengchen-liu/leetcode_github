class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) ++cnt;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        res = max(res, cnt);
        return res;
    }
};