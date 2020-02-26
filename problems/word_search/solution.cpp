class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, visited, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    // search if we can search the rest of the word starting with the grid[i, j]
    bool search(vector<vector<char>>& board,
               vector<vector<bool>>& visited, 
               string word,
               int idx,
               int i, 
               int j) {
        if (idx == word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || j < 0 || i >=m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = true;
        bool res = search(board, visited, word, idx + 1, i - 1, j ) 
                 || search(board, visited, word, idx + 1, i + 1, j)
                 || search(board, visited, word, idx + 1, i, j - 1)
                 || search(board, visited, word, idx + 1, i, j + 1);
        visited[i][j] = false;
        return res;
    }
};