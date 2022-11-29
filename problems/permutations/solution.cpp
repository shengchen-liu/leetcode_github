/*
nums = [1,2,3]

1 2 3
i 
1 [2, 3]
1 2  [3]
1 2 3
1 

dfs(cand)
    // terminate
    if cand is empty
        update res
    for each cand j:
        curPerm += j
        swap
        dfs(cands)
        swap back

*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(0, res, nums);
        return res;
    }

    void dfs(int start, vector<vector<int>>& res, vector<int>& nums) {
        // termination
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        // recursion
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            dfs(start + 1, res, nums);
            swap(nums[i], nums[start]);
        }
    }
};