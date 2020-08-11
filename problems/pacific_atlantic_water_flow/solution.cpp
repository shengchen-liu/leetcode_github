class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<vector<bool>> pacific (m, vector<bool> (n, false));
        vector<vector<bool>> atlantic (m, vector<bool> (n, false));
        // left, right
        for (int i = 0; i < m; ++i) {
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, n - 1);
        }
        
        // top, bottom
        for (int j = 0; j < n; ++j) {
            dfs(matrix, pacific, INT_MIN, 0, j);
            dfs(matrix, atlantic, INT_MIN, m - 1, j);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
        
    }
    
    void dfs(vector<vector<int>>& matrix, 
            vector<vector<bool>>& visited,
            int pre,
            int i,
            int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre) return;
        visited[i][j] = true;
        dfs(matrix, visited, matrix[i][j], i + 1, j);
        dfs(matrix, visited, matrix[i][j], i - 1, j);
        dfs(matrix, visited, matrix[i][j], i, j + 1);
        dfs(matrix, visited, matrix[i][j], i, j - 1);
    }
};