class Solution {
public:
    // return the longest ... starting from pos(i, j)
    int dfs(const vector<vector<int>>& matrix, int i, int j, 
           vector<vector<int>>& dp) {
        // termination
        if (dp[i][j] != -1)
            return dp[i][j];
        // recursion
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        dp[i][j] = 1;
        // check 4 neighbors
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j])
                continue;
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, x, y, dp));
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, i, j, dp));
            }
        }
        return res;
    }
};