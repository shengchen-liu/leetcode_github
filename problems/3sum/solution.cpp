class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // sort 
        sort(nums.begin(), nums.end()); // O(nlogn)
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i == 0 || nums[i - 1] != nums[i])
                twoSum(nums, i, res);
        }
        return res;
        
    }
    
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i + 1;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0 || (lo > i + 1 && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (sum > 0 || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) --hi;
            else
                res.push_back({nums[i], nums[lo++], nums[hi--]});
        }
    }
};