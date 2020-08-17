class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // i: element at which a sebseq of length i termintates
        vector<int> dp;
        for (auto a : nums) {
            if (find(dp.begin(), dp.end(), a) != dp.end()) continue;
            auto it = upper_bound(dp.begin(), dp.end(), a);
            if (it == dp.end()) dp.push_back(a);
            else *it = a;
        }
        return dp.size();
    }
};