/*
matrix, m x n
rearrange columns
after reording the columns, submatrix
max area of this submatrxi
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> cntOnes(m, vector<int>(n, 0));
        
        // initialize
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 1)
                cntOnes[0][j] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    cntOnes[i][j] = 0;
                else 
                    cntOnes[i][j] = cntOnes[i - 1][j] + 1;
            }
        }
        
        int res = 0;
        // traverse each row
        for (int i = 0; i < m; ++i) {
            auto cur = cntOnes[i]; // each row
            // sort
            sort(cur.begin(), cur.end(), greater()); // descending
            for (int j = 0; j < n; ++j ){
                res = max(res, cur[j] * (j + 1));
            }
        }
        return res;
    }
};