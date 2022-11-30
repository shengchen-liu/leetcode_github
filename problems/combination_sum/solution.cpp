/*
2,3,6,7
target:7

2  -> 5
2  -> 3
2  -> 1 x
3  -> 0 [2, 2, 3]

tree

                      -
                2 (5)      3(4)
              / |   \     /
           2(3) 3(2)     3(1)
           /   /
        2(1)   2(0*)

search problem, dfs
sort
f(candidates, path, start, target): starting from start, return all combinitions that sum == target
    // termination
    if target == 0:
        update res
        return
    if target <0:
        return

    // recurion
    for each cand "i" from [start, end]:
        path += cand[i]
        f(candidates, path, i, target-cand[i])
        path pop back
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, path, 0, target, res);
        return res;
    }

    void dfs(const vector<int>& candidates, vector<int> path, int start, int target, vector<vector<int>>& res) {
        // termination
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target <0) 
            return;

        // recursion
        for (int i = start; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            dfs(candidates, path, i, target - candidates[i], res);
            path.pop_back();
        }
    }
};