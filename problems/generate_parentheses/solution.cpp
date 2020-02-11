class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }
    void dfs (int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) dfs(left - 1, right, out + '(', res);
            if (right > 0) dfs(left, right - 1, out + ')', res);
        }
    }
};