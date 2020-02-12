class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
        int p = m, q = n;
        // p, q 为当前换的高度和宽度
        for (int i = 0; i < c; ++i, p -= 2, q -=2) {
            // top
            for (int col = i; col < i + q; ++col) {
                res.push_back(matrix[i][col]);
            }
            // right
            for (int row = i + 1; row < i + p; ++row) {
                res.push_back(matrix[row][i + q - 1]);
            }
            if (p == 1 || q == 1) break;
            // bottom
            for (int col = i + q - 2; col >= i; --col) {
                res.push_back(matrix[i + p - 1][col]);
            }
            // left
            for (int row =  i + p - 2; row > i; --row) {
                res.push_back(matrix[row][i]);
            }
        }
        return res;
        
    }
};