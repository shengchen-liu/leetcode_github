class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int, int>>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                vector<pair<int, int>> v;
                queue<pair<int, int>> q{{{i, j}}};
                while (!q.empty()) {
                    auto t = q.front();
                    q.pop();
                    for (auto dir : dirs) {
                        int x = t.first + dir[0];
                        int y = t.second + dir[1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= 0) continue;
                        q.push({x, y});
                        grid[x][y] *= -1;
                        v.push_back({x - i, y - j});
                    }
                }
                res.insert(v);
            }
        }
        return res.size();
    }
};