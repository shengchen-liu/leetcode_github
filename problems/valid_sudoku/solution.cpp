/**
check a line is valid? is_valid
1. each element in range of [1, 9]
2. without repetiont

for each row:
    is_valid(row)
for each col:
    is_valid(col)
for each_box:
    is_valid(box)
    
row:
    0(5)
col: (5)0
cell: 0(5)0
**/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                string t = "(" + to_string(board[i][j]) + ")";
                string row = to_string(i) + t;
                string col = t + to_string(j);
                string cell = to_string(i / 3) + t + to_string(j / 3);
                if (st.count(row) || st.count(col) || st.count(cell)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(cell);
            }
        }
        return true;
    }
};