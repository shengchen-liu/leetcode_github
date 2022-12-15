/*
target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]

0       10        20       30       60          100
        60        20       30       40
x(10)   x(60)     _(50)    _(40)    _(10)      _(-30)
x(10)   x(60)     _(50)    _(40)    x(50)      _(10)

dp[i]: farthest distance we can get using i refueling stops. 
dp[0]: startFuel

*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n + 1, 0);
        dp[0] = startFuel;

        for (int i = 0; i < n ; ++i) {
            for (int j = i + 1; j >= 1; --j) {
                if (dp[j - 1] >= stations[i][0]) {
                    dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
                }
            }
        }

        for (int j = 0; j < n + 1; ++j) {
            if (dp[j] >= target)
                return j;
        }

        return -1;
    }
};