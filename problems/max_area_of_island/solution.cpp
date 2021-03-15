class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> dx {-1, 0, 1, 0};
        vector<int> dy {0, -1, 0, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int cnt = 0;
                    queue<vector<int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        int x = t[0];
                        int y = t[1];
                        ++cnt;
                        for (int k = 0; k < 4; ++k) {
                            int x_new = x + dx[k];
                            int y_new = y + dy[k];
                            if (x_new < 0 || x_new >= m || y_new <0 || y_new >= n ||
                                grid[x_new][y_new] == 0 || visited[x_new][y_new]) 
                                continue;
                            visited[x_new][y_new] = true;
                            q.push({x_new, y_new});
                        }
                    }
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};