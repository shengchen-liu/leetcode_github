class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(n);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // cout << m << "," << n << endl;
        for (int i = 0; i < n; ++i) {
            res[i] = check(0, i, grid, visited);
        }
        
        return res;
    }
    
    // check current grid i, j's final destination
    int check(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        // termination
        if (i == m)
            return j;
        
        if (visited[i][j] != 0)
            return visited[i][j];
        
        // current dir
        int cur = grid[i][j];
        
        // cout << i << ", " << j << endl;
        // check stuck?
        // cur = 1 : right wall or v
        if (cur == 1 && (j == n - 1 || grid[i][j + 1] == -1)) {
            visited[i][j] = -1;
            return -1;
        }
        
        // cur = -1 : left wall or v
        if (cur == -1 && (j == 0 || grid[i][j - 1] == 1)) {
            visited[i][j] = -1;
            return -1;
        }
        
        int next = j + cur;
        // cout << next << endl;
        visited[i][j] = check(i + 1, next, grid, visited);
        // cout << next << endl;
        return visited[i][j];
    }
};