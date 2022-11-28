/*
n, k
return all combo of k numbs chose from range [1, n]

eg: n = 4, k =2
range: [1, 2, 3, 4]
1,2
1,3
1,4
2,3
2,4
3,4

search problem
fn(i, n, k): range [i,n], find all combs of k numbs.
    if k == 0:
        update res
        return
    for each candidate j from [i + 1, n]:
        cur_comb += j
        fn(j, n, k - 1)
        cur_comb.pop_back()
        fn(j, n, k)
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curComb;
        dfs(0, n, k, curComb, res);
        return res;
    }

    void dfs(int i, int n, int k, vector<int>& curComb, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(curComb);
            return;
        }

        // iterate
        for (int j = i + 1; j <= n; ++j) {
            curComb.push_back(j);
            dfs(j, n, k - 1, curComb, res);
            curComb.pop_back();
        }
    }
};