/*
 backtracking
 helper(int idx, cur_sum, target, path, candidates):
    if (cur_sum == target):
        res.push_back(path)
        return
    if (cur_sum > target):
        return
    
    // traverse each candidate
    for (i = idx; i < candidates.size(); ++i):
        // choose candidates[i]
        path.push_back(candidates[i])
        cur_sum += candidates[i]
        helper(i, cur_sum, target, path, candidates)
        
        // no choose candidates[i]
        path.pop_back()
        cur_sum -= candiates[i]
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        // sort
        sort(candidates.begin(), candidates.end());
        helper(0, 0, target, path, candidates, result);
        return result;
    }
    
    void helper(int idx, int cur_sum, int target, vector<int>& path, const vector<int>& candidates, vector<vector<int>>& result) {
        // termination
        if (cur_sum == target) {
            result.push_back(path);
            return;
        }
        if (cur_sum > target) {
            return;
        }
        
        // recursion
        for (int i = idx; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            cur_sum += candidates[i];
            helper(i, cur_sum, target, path, candidates, result);
            path.pop_back();
            cur_sum -= candidates[i];
        }
    }
};