/*
nums = [2, 7, 11, 15]
target = 9

return: 
[0, 1]

a + b = target
traverse each a idx in nums:
    for each b idx in nums:
        if a + b == target:
            return [a, b]

O(n^2)

solution 2:
hashmap:
2: 0
7: 1
11: 2
15: 3

for each val in hashmap:
    if map(target - val) exists
        return (val, map(target - val))

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> res;

        // construct hashmap
        for (int i = 0; i < nums.size(); ++i) {
            hashmap[nums[i]] = i;
        }
        // traverse each val
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap[target - nums[i]] && i != hashmap[target - nums[i]]) {
                res = {i, hashmap[target - nums[i]]};
                break;
            }
        }

        return res;
    }
};