class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> cols(n), diag(2 * n), anti_diag(2 * n);
        helper(n, 0, cols, diag, anti_diag, res);
        return res;
    }
    void helper(int n, int row, vector<bool>& cols, vector<bool>& diag, vector<bool>& anti_diag, int& res) {
        if (row == n) ++res;
        for (int col = 0; col < n; ++col) {
            int idx1 = col - row + n, idx2 = col + row;
            if (cols[col] || diag[idx1] || anti_diag[idx2]) continue;
            cols[col] = diag[idx1] = anti_diag[idx2] = true;
            helper(n, row + 1, cols, diag, anti_diag, res);
            cols[col] = diag[idx1] = anti_diag[idx2] = false;
        }
    }
};