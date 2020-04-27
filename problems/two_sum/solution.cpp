class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (m.count(target - num) && i != m[target - num]) {
                return {i, m[target - num]};
            }
        }
        return {};
    }
};