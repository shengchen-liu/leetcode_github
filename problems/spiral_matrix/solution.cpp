class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        int r1 = 0, r2 = m - 1;
        int c1 = 0, c2 = n - 1;
        while (r1 <= r2 && c1 <= c2) {
            // top
            for (int c = c1; c <= c2; ++c) {
                res.push_back(matrix[r1][c]);
            }
            // right
            for (int r = r1 + 1; r <= r2; ++r) {
                res.push_back(matrix[r][c2]);
            }
            if (r1 < r2 && c1 < c2) {
                // bottom
                for (int c = c2 - 1; c > c1; --c) {
                    res.push_back(matrix[r2][c]);                
                }
                // left
                for (int r = r2; r > r1; --r) {
                    res.push_back(matrix[r][c1]);
                }
            }

            
            ++r1;
            --r2;
            ++c1;
            --c2;
        }

        return res;
    }
};