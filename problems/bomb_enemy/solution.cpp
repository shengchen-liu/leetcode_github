/*
"0","E","0","0"
"E","0","W","E"
"0","E","0","0"
*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int rowHits = 0;
        vector<int> dp_col(n, 0);
        int res = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                // start from col to end of the row, update rowHits
                if (col == 0 || grid[row][col - 1] == 'W') {
                    rowHits = 0;
                    for (int k = col; k < n; ++k) {
                        if (grid[row][k] == 'W')
                            break;  // stop the scan when we hit the wall
                        else if (grid[row][k] == 'E')
                            rowHits++;
                    }
                }

                // start from row to end of the column, update colHits
                if (row == 0 || grid[row - 1][col] == 'W') {
                    int colHits = 0;
                    for (int k = row; k < m; ++k) {
                        if (grid[k][col] == 'W') 
                            break;
                        else if (grid[k][col] == 'E')
                            colHits++;
                    }
                    dp_col[col] = colHits;
                }

                // empty cell
                if (grid[row][col] == '0') {
                    res = max(res, rowHits + dp_col[col]);
                }
            }
        }
        return res;
    }
};