class Solution {
public:
//     int subarraySum(vector<int>& nums, int k) {
// //         brute force
//         int res = 0;
//         // [1, 2, 3]
//         for (int i = 0; i < nums.size(); i++){ //1
//             int remain = k - nums[i];  // 2
//             if (remain == 0) res++;
//             for (int j = i + 1; j < nums.size(); j++){ //1
//                 remain = remain - nums[j]; //remain: 0
//                 if (remain == 0) res++;
//             }
//         }
//         return res;
        
//     }
    // hashmap 
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> map{};
        map[0] = 1; 
        for (int i = 0; i < nums.size(); ++i){
            sum = sum + nums[i];
            if (map.count(sum - k)){
                count = count + map[sum-k];
            }
            ++map[sum];
        }
        return count;
    }
    
};