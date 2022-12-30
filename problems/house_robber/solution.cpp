class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        int preMax = 0;
        int curMax = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = curMax;
            curMax = max(curMax, preMax + nums[i]);
            preMax = tmp;
        }
        
        return curMax;
    }
};