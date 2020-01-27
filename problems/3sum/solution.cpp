class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();  //6
        int target = nums[0];
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == target) continue; // skip duplicats
            target = nums[i]; // fixed
            
            // 2 sum
            int p1 = i + 1;
            int p2 = n - 1;
            while (p1 < p2) {
                if (nums[p1] + nums[p2] == -target) {
                    result.push_back({target, nums[p1], nums[p2]});
                    while (p1 < p2 && nums[p1] == nums[p1 + 1]){
                        ++p1;
                    }
                    while (p1 < p2 && nums[p2] == nums[p2 - 1]){
                        --p2;
                    }
                    ++p1;
                    --p2;
                }
                else if (nums[p1] + nums[p2] > -target) {
                    --p2;
                }
                else {
                    ++p1;
                }
            }
        }
        return result;
        
    }
};