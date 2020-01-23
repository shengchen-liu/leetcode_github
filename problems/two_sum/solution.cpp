class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         hashmap
        unordered_map<int, int> map;
        //2:0, 7: 1, 11: 2, 15: 3
        for (int i = 0; i < nums.size(); i++) { // O(N)
            if (map.count(target - nums[i])) {
                return {i, map[target - nums[i]]};
            }
            map[nums[i]] = i;
        }
        return {};
        
    }
};