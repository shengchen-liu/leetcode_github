/*
1 2 2
0 0 0   -> []
1 0 0   -> [1]
0 1 0   -> [2]
0 0 1   -> [2] x
1 1 0   -> [1, 2]
1 0 1   -> [1, 2] x
1 1 1   -> [1, 2, 2]
0 1 1   -> [2, 2]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();

        // sort
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        unordered_set<string> seen;

        // traverse each bit mas
        for (int i = 0; i < pow(2, size); ++i) {
            vector<int> curSet;
            string hashcode = "";
            // iterate over each num
            for (int j = 0; j < size; ++j) {  // i = 1 1* 0, j = 1
                // mask
                int mask = 1 << j;
                if (mask & i) {
                    curSet.push_back(nums[j]);
                    hashcode += to_string(nums[j]);
                    hashcode += ",";
                }
            }

            if (seen.find(hashcode) == seen.end()) {
                res.push_back(curSet);
                seen.insert(hashcode);
            }
        }

        return res;
    }
};