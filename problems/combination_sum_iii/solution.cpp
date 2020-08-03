class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        helper(k, n, 1, out, res);
        return res;
    }
    
    void helper(int k, int n, int level, vector<int>& out,
               vector<vector<int>>& res) {
        if (n < 0) return;
        if (n == 0 && out.size() == k) res.push_back(out);
        for (int i = level; i <= 9; ++i) {
            out.push_back(i);
            helper(k , n - i, i + 1, out, res);
            out.pop_back();
        }
    }
};