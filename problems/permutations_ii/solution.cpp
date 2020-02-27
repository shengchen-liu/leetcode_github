class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        int n = nums.size();
        vector<int> visited(n);
        sort(nums.begin(), nums.end());
        dfs(nums, out, res, 0, visited);
        return res;
    }
    
    // recursion on idx of nums
    void dfs(vector<int>& nums, 
             vector<int>& out, 
             vector<vector<int>>& res ,
             int level,
             vector<int>& visited) {
        if (level >= nums.size()) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1) continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
            visited[i] = 1;
            // in-order
            out.push_back(nums[i]);
            dfs(nums, out, res, level + 1, visited);
            out.pop_back();
            visited[i] = 0;            
        }

    }
};