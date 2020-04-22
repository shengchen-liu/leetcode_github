class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while (i < n && j < n) {
            sum += nums[j];
            while (sum >= s){
                res = min(res, j - i + 1);
                sum -= nums[i];
                ++i;
            }
            ++j;
        }
        return res == INT_MAX ? 0 : res;
    }
};