class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = { 0, 0, 1, -1};

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }
        
        int dist = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                q.pop();
                // neighbor
                for (int j = 0; j < 4; ++j) {
                    int x = p.first + dx[j];
                    int y = p.second + dy[j];
                    if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] < INT_MAX)
                        continue;
                    rooms[x][y] = dist;
                    q.push({x, y});
                }
            }
            ++dist;
        }
    }
};