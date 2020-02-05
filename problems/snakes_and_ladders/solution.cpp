class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), res = 0;
        queue<int> q{{1}};
        vector<bool> visited(n * n + 1);
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                int num = q.front(); q.pop();
                if (num == n * n) return res;
                for (int i = 1; i <= 6 && num + i <= n * n; ++i) {
                    int next = getBoardValue(board, num + i);
                    if (next == -1) next = num + i;
                    if (visited[next]) continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            ++res;
        }
        return -1;
    }
    int getBoardValue(vector<vector<int>>& board, int num) {
        int n = board.size(), x = (num - 1) / n, y = (num - 1) % n;
        if (x % 2 == 1) y = n - 1 - y;
        x = n - 1 - x;
        return board[x][y];
    }
};