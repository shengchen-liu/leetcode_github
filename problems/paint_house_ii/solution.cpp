/*
1,5,3
2,9,4

dp[i][j]: min cost to paint first i houses, ith house has color j
dp[i][j] = costs[i-1][j] + min(dp[i-1][r], r in (0 to k exept j))
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<int> previousRow(k, 0);
        vector<int> currentRow(k, 0);

        for (int i = 1; i <= n; ++i) {
            // Find the minimum and second minimum color in the PREVIOUS row.
            int minColor = -1; int secondMinColor = -1;
            for (int color = 0; color < k; color++) {
                int cost = previousRow[color];
                if (minColor == -1 || cost < previousRow[minColor]) {
                    secondMinColor = minColor;
                    minColor = color;
                } else if (secondMinColor == -1 || cost < previousRow[secondMinColor]) {
                    secondMinColor = color;
                }
            }

            // And now calculate the new costs for the current row.
            for (int color = 0; color < k; ++color) {
                if (color == minColor)
                    currentRow[color] = previousRow[secondMinColor] + costs[i - 1][color];
                else 
                    currentRow[color] = previousRow[minColor] + costs[i - 1][color];
            }
            previousRow = currentRow;
        }
        int res = INT_MAX;
        for (int i = 0; i < k; ++i) {
            res = min(res, currentRow[i]);
        }
        return res;
    }
};