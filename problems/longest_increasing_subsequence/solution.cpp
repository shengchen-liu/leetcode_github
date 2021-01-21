/*
O(nlogn)
dp[i]: the smallest ending number of a subsequence that has length+1
10,9,2,5,3,7,101,18
num      dp
10       [10]  // [10]
9        [9]   //  [9]
2        [2]   // [2]
5        [2,5]  // [2], [*, 5]
3        [2,3]  // [2], [*, 3]
7        [2,3,7] // [2], [*,3], [*, *, 7]
101      [2,3,7,101] // [2], [*,3], [*,*,7], [*,*,*,101]
18       [2,3,7,18]   //[2], [*,3], [*,*,7], [*,*,*,18]
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int x : nums) {
            auto it = lower_bound(begin(dp), end(dp), x); // find the 1st elem that is >= x
            if (it == end(dp)){
                dp.push_back(x);
            } else {
                *it = x;
            }
        }
        return dp.size();
    }
};