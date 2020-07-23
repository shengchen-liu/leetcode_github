class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto grid = q.front();
            q.pop();
            // check if we have reached the dest
            if (grid == destination) return true;
            
            // check its neighbor
            for (int i = 0; i < 4; ++i) {
                // four directions
                // stop when the reaches to the bundaries or next grid is a wall
                int x = grid[0];
                int y = grid[1];
                while (x >= 0 && x < m && y >= 0 && y < n && 
                       maze[x][y] == 0) {
                    x += dx[i];
                    y += dy[i];
                }
                x -= dx[i];
                y -= dy[i];
                if (visited[x][y]) continue;
                visited[x][y] = true;
                q.push({x, y});
            }
        }
        return false;
    }
};