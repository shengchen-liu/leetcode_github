/*
1 2 3  => 1 2 3
4 0 5     4 5 0

0:
4 1 2
5 0 3

1:
4 1 2
0 5 3

2:
0 1 2
4 5 3

3:
1 0 2
4 5 3

4:
1 2 0
4 5 3

5: 
1 2 3
4 5 0

BFS

while (!queue is empty):
    get queue.size
    for i in range (0, size):
        cur_state = queue[i]
        check_finish(cur_state) == true? return cnt
        for cand in 4 candidates:
            check cand is valid
            check the cur state is not visited
            queue.push(state)
            update visited
    ++cnt
return -1
    

*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 0, m = board.size(), n = board[0].size();
        string target = "123450", start = "";
        vector<vector<int>> dirs{{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += to_string(board[i][j]);
            }
        }
        unordered_set<string> visited{start};
        queue<string> q{{start}};
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                string cur = q.front(); q.pop();
                if (cur == target) return res;
                int zero_idx = cur.find("0");
                for (int dir : dirs[zero_idx]) {
                    string cand = cur;
                    swap(cand[dir], cand[zero_idx]);
                    if (visited.count(cand)) continue;
                    visited.insert(cand);
                    q.push(cand);
                }
            }
            ++res;
        }
        return -1;
    }
};