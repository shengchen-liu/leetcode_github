class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(nums, path, res, 0);
        return res;
    }
    
    // construct a path that is currently at 'layer'.
    void helper(vector<int>& nums, 
                vector<int>& path, 
                vector<vector<int>>& res,
                int layer) {
        // termination
        int n = nums.size();
        if (layer ==  n) {
            res.push_back(path);
            return;
        }
        
        // recursion
        // candidates: layer ~ n -1
        for (int i = layer; i < n; ++i) {
            path.push_back(nums[i]);
            swap(nums[i], nums[layer]);
            helper(nums, path, res, layer + 1);
            path.pop_back();
            swap(nums[i], nums[layer]);
        }
    }
};