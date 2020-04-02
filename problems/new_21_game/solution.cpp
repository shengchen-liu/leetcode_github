class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double sumW = 1.0, res = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = sumW / W;
            if (i < K) sumW += dp[i];
            else res += dp[i];
            if (i - W >= 0) sumW -= dp[i - W];
        }
        return res;
    }
};
