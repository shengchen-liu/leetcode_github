/*
candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
step1: sort => [1,1,2,5,6,7,10]
dfs(start): 
if target < 0:
    return
if target == 0:
    update res
    return
for each cand i from start to last:
    if (i > start && candidates[i] == candidates[i - 1]) continue;
    path += candidates[i]
    dfs(i + 1, path)
    path.pop_back

*/class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, path, res, candidates);
        return res;
    }

    void dfs(int start, int target, vector<int>& path, vector<vector<int>>& res, const vector<int>& candidates) {
        // termination
        if (target < 0)
            return;
        if (target == 0) {
            res.push_back(path);
            return;
        }

        // recursion
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], path, res, candidates);
            path.pop_back();
        }
    }
};