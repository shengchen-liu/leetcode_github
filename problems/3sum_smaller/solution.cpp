/*
nums[i] :
find nums[j] + nums[k] < target - nums[i]
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) return res;
        for (int i = 0; i < nums.size() - 2; ++i) {
            twoSumSmaller(i + 1, target - nums[i], nums, res);
        }
        return res;
    }
    
    void twoSumSmaller(int i, int target, vector<int> &nums, int &res) {
        int j = i;
        int k = nums.size() - 1;
        while (j < k) {
            if (nums[j] + nums[k] < target) {
                res += k - j;
                ++j;
            } else --k;
        }
    }
};