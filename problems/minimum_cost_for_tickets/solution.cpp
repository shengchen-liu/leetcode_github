/**
1. Track calendar days
We track the minimum cost for all calendar days in dp. For non-travel days, the cost stays the same as for the previous day. For travel days, it's a minimum of yesterday's cost plus single-day ticket, or cost for 8 days ago plus 7-day pass, or cost 31 days ago plus 30-day pass.


**/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      unordered_set<int> travel(begin(days), end(days));
      int dp[366] = {};
      for (int i = 1; i < 366; ++i) {
        if (travel.find(i) == travel.end()) dp[i] = dp[i - 1]; // non-travel day
        else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
      }
      return dp[365];
    }
};