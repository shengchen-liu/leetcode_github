class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int> &tmp, int i) {
        // termination
        int n = nums.size();
        if (i == n){
            res.push_back(tmp);
            return;
        }
        
        // recursion
        // don't include current val
        dfs(nums, res, tmp, i + 1);
        
        // include current val
        tmp.push_back(nums[i]);
        dfs(nums, res, tmp, i + 1);
        tmp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        // back tracking
        vector<int> tmp;
        dfs(nums, res, tmp, 0);
        return res;
    }
};