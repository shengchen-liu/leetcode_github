/*
search 

[1, 2, 2]
1. sort (nlogn)
2. dfs

                          /1                      \[]
                         {1}                       {}
                      /2    \[]                  /2      \[]
                {1, 2}      {2}                 {2}       {} 

dfs(i, nums, cur, res):
    // termination
    if i == nums.size:
        res += cur
        return
    // recursion
    // keep
    if i == 0 or nums[i] > nums[i - 1]:
        add nums[i] to cur
        dfs(i + 1, nums, cur, res)
        delete nums[i]
    // no keep
    else: 
        dfs(i + 1, nums, cur, res)

*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        // sort
        sort(nums.begin(), nums.end());
        vector<int> cur;
        dfs(0, nums, cur, res);
        return res;
    }

    // dfs
    void dfs(int i, const vector<int>& nums,  vector<int>& cur, vector<vector<int>>& res) {
        // operate on current level
        res.push_back(cur);

        // iterate each candidate
        for (int j = i; j < nums.size(); ++j) {
            if (j != i && nums[j] == nums[j - 1]) {
                continue;
            }
            cur.push_back(nums[j]);
            dfs(j+1, nums, cur, res);
            cur.pop_back();
        }
    }
};