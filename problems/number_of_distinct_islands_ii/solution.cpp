class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    vector<pair<int, int>> shape;
                    helper(grid, i, j, shape);
                    st.insert(normalize(shape));
                }
            }
        }
        return st.size();
    }
    
    void helper(vector<vector<int>>& grid, int x, int y, vector<pair<int, int>>& shape) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if (grid[x][y] == 0) return;
        grid[x][y] = 0;
        shape.push_back({x, y});
        helper(grid, x + 1, y, shape);
        helper(grid, x - 1, y, shape);
        helper(grid, x, y + 1, shape);
        helper(grid, x, y - 1, shape);
    }
    
    vector<pair<int, int>> normalize(vector<pair<int, int>>& shape) {
                vector<vector<pair<int, int>>> shapes(8);
        for (auto &a : shape) {
            int x = a.first, y = a.second;
            shapes[0].push_back({x, y});
            shapes[1].push_back({x, -y});
            shapes[2].push_back({-x, y});
            shapes[3].push_back({-x, -y});
            shapes[4].push_back({y, x});
            shapes[5].push_back({y, -x});
            shapes[6].push_back({-y, x});
            shapes[7].push_back({-y, -x});
        }
        for (auto &a : shapes) {
            sort(a.begin(), a.end());
            for (int i = (int)shape.size() - 1; i >= 0; --i) {
                a[i].first -= a[0].first;
                a[i].second -= a[0].second;
            }
        }
        sort(shapes.begin(), shapes.end());
        return shapes[0];
    }
    
};