// unsorted
// for i1 in array:
//     i1
//     for i2 in rest of array:
//         if i1 + i2 == target:
//            return [i1.index, i2.index]
// 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        //O(N) Hashmap
        /**
        {
            2: 0
            7: 1
            11: 2
            15: 3
        }
        **/
        unordered_map<int, int> map;
        int size = nums.size();
        for (int i = 0; i < size; i++){
            // n1, find targe-n1
            // you should never iterate a hashmap
            if(map.count(target - nums[i]) && map[target - nums[i]] != i){
                return {i, map[target-nums[i]]};
            }
            map[nums[i]] = i;
            
        }

        return{};
    }
};