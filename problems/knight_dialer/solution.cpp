/*
n = 2
1 2 3 
4 5 6
7 8 9
  0

hashmap
0: 4, 6
1: 6, 8
2: 7, 9
3: 4, 8
4: 3, 9, 0
6: 1, 7, 0
7: 2, 6
8: 1, 3
9: 2, 4

dfs permutation
memo[i][k]
we are currently at num i, k jumps remaining
if k == 0:
    return 0

cnt = 0
for all possbible dests of i:
    check momo
    move to dest
    update path
    cnt += dfs(dest, k-1, path, cnt)
    remove dest from path
*/
class Solution {
public:
    int knightDialer(int N) {
        int res = 0, M = 1e9 + 7;
        vector<vector<int>> dp(N, vector<int>(10));
        vector<vector<int>> path{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 9}, {4, 2}};
        for (int i = 0; i < 10; ++i) dp[0][i] = 1;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int idx : path[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][idx]) % M;
                }
            }
        }
        for (int i = 0; i < 10; ++i) res = (res + dp.back()[i]) % M;
        return res;
    }
};