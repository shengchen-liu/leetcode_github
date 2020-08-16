class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1. transpose
        int n = matrix.size();
        if (n == 0) return;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        // 2. reverse cols
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }     
    }
};