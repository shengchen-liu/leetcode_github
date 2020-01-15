class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());        
        vector<int> out;
        vector<vector<int>> result;
        helper(candidates, target, out, result, 0);
        return result;
    }
    void helper(vector<int>& candidates,
               int target,
               vector<int>& out,
               vector<vector<int>>& result,
               int start){
        if (target < 0) return;
        if (target == 0){
            result.push_back(out);
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            if (candidates[i] > target) break;
            if (i > start && candidates[i] == candidates[i-1]) continue;
            out.push_back(candidates[i]);
            helper(candidates, target - candidates[i], out, result, i + 1);
            out.pop_back();
        }
    }
    
};