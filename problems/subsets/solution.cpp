class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> path;
        vector<vector<int>> res;
        helper(0, nums, path, res);
        return res;
    }
    
    void helper(int i, vector<int>& nums, vector<int>& path, 
                vector<vector<int>> &res) {
        if (i == nums.size()) {
            res.push_back(path);
            return;
        }
                
        // 2. include nums[i]
        path.push_back(nums[i]); // path : [1]
        helper(i + 1, nums, path, res);
        
        // 1. don't include nums[i]
        path.pop_back();
        helper(i + 1, nums, path, res);
    }
};