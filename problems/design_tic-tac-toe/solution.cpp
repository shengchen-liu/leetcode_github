class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n);
        cols.resize(n);
        diag = 0;
        off_diag = 0;
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // player 1: +1
        // player 2: -1
        int add = player == 1 ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diag += (row == col ? add : 0);
        off_diag += (row == N - col - 1 ? add : 0);
        
        // check
        return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N || abs(off_diag) == N) ? player : 0;
        
    }
    
private:
    vector<int> rows;
    vector<int> cols;
    int diag;
    int off_diag;
    int N;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */