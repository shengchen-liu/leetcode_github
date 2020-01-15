class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> out;
        vector<vector<int>> result;
        helper(candidates, out, result, 0, target);
        return result;
    }
    
    void helper(vector<int>& candidates, 
                vector<int>& out, 
                vector<vector<int>>& result, 
                int start, 
                int target){
        if (target < 0) return;
        if (target == 0){
            result.push_back(out);
        }
        for (int i = start; i < candidates.size(); i++){
            if (candidates[i] > target) break;
            out.push_back(candidates[i]);
            helper(candidates, out, result, i, target - candidates[i]);
            out.pop_back();
        }
    }
    
};