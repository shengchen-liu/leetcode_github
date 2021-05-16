/*
5,1,6
subsets
5
1
6
5,1
5,6
1,6
5,1,6

combinition
*/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int cur_xor = 0;
        dfs(nums, res, 0, cur_xor);
        return res;
    }
    
    void dfs(const vector<int>& nums, int &res, int idx, int cur_xor) {
        // termination
        int n = nums.size();
        if (idx == n) {
            res += cur_xor;
            return;
        }
        
        // recursion
        // i is in subset
        dfs(nums, res, idx + 1, cur_xor ^ nums[idx]);
        dfs(nums, res, idx + 1, cur_xor);
    }
};