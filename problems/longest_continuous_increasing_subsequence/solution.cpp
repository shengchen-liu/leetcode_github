class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int res = 1;

        if (n == 1) return 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]){
                cnt++;
                res = max(res, cnt);
            }
            else {
                cnt = 1;
            }
        }
        return res;
    }
};