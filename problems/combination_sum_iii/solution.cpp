/*
1 2 3 4 5 6 7 8 9
target: 7
k: 3

dfs(start, path, k, n)
if n < 0:
    return
if k == 0 and n == 0:
    update res
    return
for (i = start; i <= 9; ++i) {
    path.push_back(i)
    dfs(i + 1, path, k - 1, n - i)
    path.pop_out
}
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1, path, k, n, res);
        return res;
    }
    void dfs(int start, vector<int>& path, int k, int n, vector<vector<int>>& res) {
        // termination
        if (n < 0 || k < 0)
            return;
        if (n == 0 && k == 0) {
            res.push_back(path);
            return;
        }

        // recursion
        for (int i = start; i <= 9; ++i) {
            path.push_back(i);
            dfs(i + 1, path, k - 1, n - i, res);
            path.pop_back();
        }
    }
};