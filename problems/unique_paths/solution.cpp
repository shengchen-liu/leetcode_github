class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) cur[j] = 1;
                else {
                    cur[j] = cur[j] + cur[j - 1];
                }
            }
        }
        return cur[n - 1];
    }
};