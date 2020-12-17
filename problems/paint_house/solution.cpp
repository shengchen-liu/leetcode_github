/*
n houses, each house one of 3 colors: R,B,G
cost: n x 3 matrix
no two adjacent houses have same color
cost[][0]: R
cost[][1]: B
cost[][2]: G
find min cost to paint all houses
cost:
 R  B  G
[17,2,17],
[16,16,5],
[14,3,19]

n = 3
dp size: (n + 1) x 3
dp[i][j]: min cost to paint first i houses (1-base), curr house has color j  
vs dp[i-1][?]
if j = 0:
    dp[i][j] = cost[i][j] + 
                min(dp[i-1][1], dp[i-1][2])
if j = 1:
        dp[i][j] = cost[i][j] + 
                min(dp[i-1][0], dp[i-1][2])
if j = 2:
        dp[i][j] = cost[i][j] + 
                min(dp[i-1][0], dp[i-1][1])
initial:
    dp[0][..] = 0

return min(dp[n][0], dp[n][1], dp[n][2])
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
        // dp
        // initial 
        for (int i = 0; i < 3; ++i){
            dp[0][i] = 0;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = costs[i - 1][j];
                if (j == 0){
                    dp[i][j] += min(dp[i - 1][1], dp[i-1][2]);
                } else if (j == 1){
                    dp[i][j] += min(dp[i - 1][0], dp[i-1][2]);
                } else {
                    dp[i][j] += min(dp[i - 1][0], dp[i-1][1]);
                }
            }
        }
        
        int res = INT_MAX;
        res = min(dp[n][0], min(dp[n][1], dp[n][2]));
        return res;
    }
};