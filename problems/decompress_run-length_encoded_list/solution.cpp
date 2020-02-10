class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int n = nums.size(); // 4
        vector<int> result;
        for(int i(0); i < n; i+=2){
            result.insert(result.end(),nums[i],nums[i+1]);
        }
        return result;
    }
};