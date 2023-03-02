class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j])
                    continue;
                if (dfs(i, j, board, word, 0, visited))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, const vector<vector<char>>& board, string word, int k, vector<vector<bool>> &visited){
        int m = board.size();
        int n = board[0].size();
        if (k == word.size())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[k]) 
            return false;

        visited[i][j] = true;
        bool res = dfs(i + 1, j, board, word, k + 1, visited) ||
                    dfs(i - 1, j, board, word, k + 1, visited) ||
                    dfs(i, j + 1, board, word, k + 1, visited) ||
                    dfs(i, j - 1, board, word, k + 1, visited);
        visited[i][j] = false;
        return res;
    }
};