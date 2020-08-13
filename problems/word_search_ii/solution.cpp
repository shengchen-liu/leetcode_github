struct Node {
    Node * ch[26];
    string str;
    Node() {
        for (int i = 0; i < 26; ++i) {
            ch[i] = NULL;
            str = "";
        }
    }
};


class Solution {
public:
    vector<string> results;
    Node* root;
    void insert(Node* p, string s) {
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (p->ch[s[i] - 'a'] == NULL) {
                // current node is empty
                p->ch[s[i] - 'a'] = new Node();
            }
            p =  p->ch[s[i] - 'a'];
        }
        p->str = s;
    }
        
    void search(vector<vector<char>>& board,
               vector<vector<bool>>& mask,
               Node* p,
               int x, 
               int y) {
        if (p->str != "") { // if it is a leaf
            results.push_back(p->str);
            p->str = "";
        }
        
        mask[x][y] = false; //标记mask[x][y]，避免重复访问
        // check neighbor
        int m = board.size();
        int n = board[0].size();
        vector<int> d_x = {1, 0, -1, 0};
        vector<int> d_y = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int newX = x + d_x[i];
            int newY = y + d_y[i];
            if (newX < 0 || newX >= m || newY < 0 || newY >= n 
                || !mask[newX][newY] 
                || !p->ch[board[newX][newY] - 'a']) continue;
            search(board, mask, p->ch[board[newX][newY] - 'a'], newX, newY);
        }
        mask[x][y] = true; //搜索后mask[x][y]可以访问
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        root = new Node();
        int len = words.size();
        for (int i = 0; i < len; ++i) { 		//插入单词构造字典树
            insert(root, words[i]);
        }
        vector<vector<bool> > mask(board.size(), vector<bool>(board[0].size(), true));
        if (board.size() < 1) return results;
        for (int i = 0; i <board.size(); ++i) {		//遍历字母矩阵，将每个字母作为单词首字母开始搜索
            for (int j = 0; j < board[0].size(); ++j) {
               if (root->ch[board[i][j]-'a'] != NULL) {			
                    search(board, mask, root->ch[board[i][j]-'a'], i, j);  //开始dfs搜索
                 }
            }
        }
        return results;
    }
};