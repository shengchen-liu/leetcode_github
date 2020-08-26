class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // totoal number of unique paths at grid[i][j]
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n, 0);
        vector<int> cur(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // top edge
                if (obstacleGrid[i][j] == 1) cur[j] = 0;
                else if (i == 0 && j == 0) cur[j] = 1; 
                else if (i == 0) cur[j] = cur[j - 1];
                else if (j == 0) cur[j] = prev[j];
                else cur[j] = cur[j - 1] + prev[j];
            }
            prev = cur;
        }
        return cur[n - 1];
    }
};