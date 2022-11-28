/*

1 2 3
0 0 0
0 0 1
0 1 0
1 0 0


*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = 1 << n;  // '1000'
        vector<vector<int>> res;  // size = 8
        for (int i = 0; i < p; ++i) {  // bit mask   '100'
            // subset corresponding to that bitmask
            vector<int> tmp;
            for (int j = 0; j < n; ++j) {  
                if ((i >> j) & 1) {
                    tmp.push_back(nums[j]);
                }
            }
            res.push_back(tmp);
        }

        return res;
        
    }
};