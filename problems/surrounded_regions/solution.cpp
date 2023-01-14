/*
for i 0 to m:
    for j 0 to n:
        if board[i][j] == 0 and not on boarder:
            //bfs to find connected region
            queue q({i,j})
            candidates = {}
            while q ! empty:
                cell = q.top
                visited[i][j] = true
                candidates.push_back({i,j})
                for each neighbor:
                    if neighbor == '0'  and not visited:
                        if  neighbor not in boundary
                            q.push(neighbor)
                        else 
                            candidate.clear
                            break
            
            if candidates not empty:
                set each candidate 'x'
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // find all 0 on boundaries. use dfs to find all connected regions, mark them as E
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> boarders;
        // 1st col: {i, 0}
        // col n-1: {i, n-1}
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, board);
            dfs(i, n - 1, board);
        }

        // row 0 : {0, i}
        // row m - 1: {m - 1, i}
        for (int i = 0; i < n; ++i) {
            dfs(0, i, board);
            dfs(m - 1, i, board);
        } 

        // for each cell, mark remaining 0 as x; convert E as 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size(); 
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;
        board[i][j] = 'E';
        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
    }
};