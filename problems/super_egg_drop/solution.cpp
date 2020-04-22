/*
f[N, K]: with K eggs remainining, the min attempt to to find the answer when dropping from flook N.
for i in range (N):
    F[1, ] = 1
    f[N, K] = min(1 + max(f[N - 1, K - 1], F[N - i, K]))
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
};