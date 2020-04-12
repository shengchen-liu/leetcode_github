class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<1501> dp = {1};
        int sumA = 0;
        for (int a : stones) {
            sumA += a;
            for (int i = min(1500, sumA); i >= a; --i) {
                dp[i] = dp[i] + dp[i - a];
            }
        }
        for (int i = sumA / 2; i > 0; --i) {
            if (dp[i]) return sumA - i - i;
        }
        return 0;
    }
};