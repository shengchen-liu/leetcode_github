class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> res;
        vector<string> queens(n, string(n, '.'));
        helper(0, queens, res);
        return res;
    }
    
    void helper(int curRow, vector<string>& queens, vector<vector<string>>& res) {
        int n = queens.size();
        if (curRow == n) {
            res.push_back(queens);
            return;
        }
        
        // for each col
        for (int i = 0; i < n; ++i) {
            if (isValid(queens, curRow, i)) {
                queens[curRow][i] = 'Q';
                helper(curRow + 1, queens, res);
                queens[curRow][i] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& queens, int x, int y) {
        for (int i = 0; i < x; ++i) {
            if (queens[i][y] == 'Q') return false;
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
            if (queens[i][j] == 'Q') return false;
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < queens.size(); --i, ++j)
        {
            if (queens[i][j] == 'Q') return false;
        }
        return true;    
    }
};