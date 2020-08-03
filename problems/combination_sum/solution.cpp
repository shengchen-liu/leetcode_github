class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> out;
        vector<vector<int>> res;
        helper(candidates, target, res, 0, out);
        return res;
    }
    
    // from index start, check candidates from start to end can sum up to target 
    void helper(vector<int>& candidates, 
                int target,
                vector<vector<int>> &res, 
                int start,
               vector<int>& out) {
        if (target < 0) return;
        if (target == 0) res.push_back(out);
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            out.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, i, out);
            out.pop_back();
        }
        
    }
};