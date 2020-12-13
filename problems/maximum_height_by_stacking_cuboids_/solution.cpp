/*
box: w, l, h
top vs lower:
top.w <= lower.w AND top.l <= lower.l
max height

dp
1. rotate box
h, l, w
[50,45,20]:[45,20, 50], [20, 50, 45]
[95,37,53]:[37,53, 95], [53, 95,37]
[45,23,12]: ...

// sorting
1. sort each box
[50,45,20]: [20, 45, 50]
[95,37,53]: [37, 53, 95]
[45,23,12]: [12, 23, 45]
2. sort by w
[12, 23, 45], [20, 45, 50], [37, 53, 95]

3. dp




*/
class Solution {
public:

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& a :cuboids)
            sort(begin(a), end(a));
        cuboids.push_back({0, 0, 0});
        sort(begin(cuboids), end(cuboids));
        int n = cuboids.size(), res = 0;
        vector<int> dp(n);
        for (int j = 1; j < n; ++j)
            for (int i = 0; i < j; ++i)
                if (cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]) {
                    dp[j] = max(dp[j], dp[i] + cuboids[j][2]);
                    res = max(res, dp[j]);
                }
        return res;
    }
};