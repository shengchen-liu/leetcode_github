/*
dfs
each num, 2 choices: 1. include it; 2. not include
(1)       [_]                 1
(2)        [_, _],               [_, 2]     [1, _], [1, 2]
(3) [_, _, _], [_, _, 3], [_, 2, _], [_, 2, 3]     [1, _], [1, 2]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }
    
    void dfs(vector<int>& nums, 
             int layer, 
             vector<int>& subset, 
             vector<vector<int>>& res) {
        // termination condition
            if (layer == nums.size()) {
                res.push_back(subset);
                return;
            }
        
        // recursion
        int num = nums[layer];
        // 1. include num in subset
        subset.push_back(num);
        dfs(nums, layer + 1, subset, res);
        
        // 2. not include num in subset
        subset.pop_back();
        dfs(nums, layer + 1, subset, res);
    }
};