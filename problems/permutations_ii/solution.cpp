class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, visited, path, res);
        return res;
    }
    
    void dfs(vector<int>& nums, 
             vector<bool>& visited, 
             vector<int>& path,
             vector<vector<int>> &res
            ) {
        // termination
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // recursion
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;
            path.push_back(cur);
            visited[i] = true;
            dfs(nums, visited, path, res);
            path.pop_back();
            visited[i] = false;
        }
    }
};