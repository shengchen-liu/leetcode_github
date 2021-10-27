/*
1, 2, 2

               _,         1
       /         \         /    \
    _,_           _,2           1,_              1,2
  /   \          /  \        /       \             /\
_,_,_ _,_,2   _,2,_ _,2,2   1,_,_   1,_,2         1,2,_ 1,2,2
[]    [2]     [2]      [2,2]   [1]   [1,2]        [1,2], [1,2,2]

1. sort the array in ascending order
2. dfs: starting at start_idx, traverse all nums.  update res
dfs(res, curr_set, nums, start_idx):
    for i from start_idx to n:
        // current num is duplicate
        if (i != start_idx and nums[i] == nums[i - 1])
            continue
        curr_set.push_back(nums[i])
        dfs(res, curr_set, nums, i + 1)
        curr_set.pop_back
    
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur_set;
        // 1. sort
        sort(nums.begin(), nums.end());
        dfs(res, cur_set, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& cur_set, const vector<int>& nums, int idx) {
        // add current set into res
        res.push_back(cur_set);
        
        for (int i = idx; i < nums.size(); ++i) {
            if (i != idx && nums[i] == nums[i - 1]) {
                continue;
            }
            cur_set.push_back(nums[i]);
            dfs(res, cur_set, nums, i + 1);
            cur_set.pop_back();
        }
    }
};