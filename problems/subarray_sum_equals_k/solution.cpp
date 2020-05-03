/*
nums = [1, 1, 1], k = 2
vector[i] : sum[0, i]

*/
class Solution {
public:
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