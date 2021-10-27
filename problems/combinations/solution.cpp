/*
n, k
k numbers [1, n]
n = 4, k = 2
2 numbers [1, 4]
1,2
1,3
1,4
2,3
2,4
3,4

searching problem.
combine k from [1, n]

suppose 1st num: a => [a, ...]
    combine k - 1 from [a + 1, n]
    
dfs(res, cur_set,n, k, idx): in the range of [idx, n], combine k numbers, 
    
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur_set;
        dfs(res, cur_set, n, k, 1);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& cur_set, int n, int k, int idx) {
        // termination
        if (k == 0) {
            res.push_back(cur_set);
            return;
        }
        
        // traverse candidates
        for (int i = idx; i < n + 1 ; ++i) {
            cur_set.push_back(i);
            dfs(res, cur_set, n, k - 1, i + 1);
            cur_set.pop_back();

        }
    }
};