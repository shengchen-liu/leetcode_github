/*
gate to nearest empty room
BFS

*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> q;
        if (rooms.size() == 0) return;
        int m = rooms.size();
        int n = rooms[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j){
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }                
        }
        // [0, 2], [3, 0]
        
        // BFS
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                auto node = q.front();
                q.pop();
                int x = node[0];
                int y = node[1];
                
                // check its neighbor
                for (int i = 0; i < 4; ++i) {
                    int x_new = x + dx[i];
                    int y_new = y + dy[i];
                    if (x_new < 0 || x_new >= m || y_new < 0 || y_new >= n 
                    || rooms[x_new][y_new] < INT_MAX ) continue;
                    rooms[x_new][y_new] = rooms[x][y] + 1;
                    q.push({x_new, y_new});
                }
            }
        }
    }
};