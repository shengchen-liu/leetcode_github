class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int x = 0;
        int y = 0;
        int dist = 0;
        int dir = 0;
        
        set<pair<int, int>> obstacleSet;
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
        
        for (int command : commands) {
            if (command == -2) {
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                dir = (dir + 1) % 4;
            } else {
                for (int k = 0; k < command; ++k) {
                    if (obstacleSet.count(make_pair(x + dx[dir], y + dy[dir]))) break;
                    x += dx[dir];
                    y += dy[dir];
                }
            }
            dist = max(dist, x * x + y * y);
        }
        return dist;
    }
};