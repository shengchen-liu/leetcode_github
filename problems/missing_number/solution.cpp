/*
[0, 3]
3, 0, 1
counting sort:
3: [3, 0, ]
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            res ^= i ^ nums[i];
        }
        return res;
    }
};