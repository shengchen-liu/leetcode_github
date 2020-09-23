/*
 [2,3,6,7]
 1. sort 
 2. backtracking
 
 0:                          2,                             3, 6, 7
 1:               2[4]              3[5],  6[8x], 7[x]
 2:          2[6], 3[7Y],           3[8x] 
 3: 2[8x]
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        helper(res, path, candidates, target, 0);
        return res;
    }
    
    // backtracking
    void helper(vector<vector<int>> &res, 
                vector<int>& path, 
                vector<int>& candidates,
                int target,
                int layer) {
        // termination
        int n = candidates.size();
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }
        
        // recursing
        // we are at current layer
        for (int i = layer; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            helper(res, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};