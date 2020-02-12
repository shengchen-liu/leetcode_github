class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int up = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int val = 1;
        while (true) {
            //top
            for (int j  = left; j <= right; ++j) {
                res[up][j] = val++; 
            }
            if (++up > bottom) break;
            //right
            for (int i = up; i <= bottom; ++i) {
                res[i][right] = val++;
            }
            if (--right < left) break;
            //bottom
            for (int j = right; j >= left; --j) {
                res[bottom][j] = val++;
            }
            if (--bottom < up) break;
            //left
            for (int i = bottom; i >= up; --i) {
                res[i][left] = val++;
            }
            if (++left > right) break;
        }
        return res;
        
    }
};