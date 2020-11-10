/*
-1,0,1,2,-1,-4
sort
-4, -1, -1, 0, 1, 2
a=-1:
    b + c = -a

*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            if (a > 0) break;
            if (i == 0 || nums[i - 1] != nums[i])
                twoSum(nums, i, res);
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, int start, vector<vector<int>>& res) {
        int left = start + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[start];
            if (sum < 0 || (left > start + 1 && nums[left] == nums[left - 1]))
                ++left;
            else if (sum > 0 || (right < nums.size() - 1 && nums[right] == nums[right + 1]))
                --right;
            else res.push_back({nums[start], nums[left++], nums[right--]});
        }
    }
};