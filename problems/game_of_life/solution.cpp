/**
1. live AND neighbor < 2: die
2. live AND neighbor == 2, 3 : live
3. live AND neighbor > 3: die
4. dead AND 3 live neighbors: live

状态0： 死细胞转为死细胞

状态1： 活细胞转为活细胞

状态2： 活细胞转为死细胞

状态3： 死细胞转为活细胞

最后对所有状态对2取余，则状态0和2就变成死细胞，状态1和3就是活细胞，达成目的。

**/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dx {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> dy {-1, -1, -1, 0, 0, 1, 1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >=0 && x < m && y >=0 && y < n && 
                        (board[x][y] == 1 || board[x][y] == 2)) {
                        ++count;
                    }
                }
                if (board[i][j] == 1 && (count < 2 || count > 3)) board[i][j] = 2;
                else if (board[i][j] == 0 && count == 3) board[i][j] = 3;
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};