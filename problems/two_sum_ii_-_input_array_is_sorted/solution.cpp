// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int i = 0;
//         int j = numbers.size() - 1;
//         vector<int> result;
//         while (i < j){
//             int s = numbers[i] + numbers[j];
//             if (s == target){
//                 result.push_back(i+1);
//                 result.push_back(j+1);
//                 break;
//             }
//             if (s > target) j--;
//             else i++;
            
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
        value | index
        2: 1
        7: 2
        11: 3
        15: 4
        */
        unordered_map<int, int> hashmap;
        for (int i = 0; i < numbers.size(); ++i) {
            hashmap[numbers[i]] = i + 1; // 2: 1
        }
        for (int i = 0; i < numbers.size(); ++i) {
            if (hashmap.count(target - numbers[i])){  // 7?
                return {i + 1, hashmap[target - numbers[i]]};
            }
        }
        return {};
    }
};