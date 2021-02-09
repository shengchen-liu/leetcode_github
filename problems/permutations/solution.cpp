/* 
1,2,3,4 
i
1: f{2,3,4}:
    1, 2, f{3,4}
    1, 3, f{2,4}
2, f{1, 3, 4}

3， f{1,2,4}

4, f{1,2,3}
*/
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
            path.push_back(nums[i]); // path: 1
            swap(nums[i], nums[layer]); // i has been visited
            helper(nums, path, res, layer + 1); // dfs
            path.pop_back();
            swap(nums[i], nums[layer]);
        }
    }
};