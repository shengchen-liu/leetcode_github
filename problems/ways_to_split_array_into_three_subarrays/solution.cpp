/*
a | sum - a - b | b

a <= sum - a - b <= b

suppose b is fixed
we have two unequality
1. a <= sum - a - b => a <= (sum - b) / 2
2. sum - a - b <= b => a >= (sum - 2b)
so a is in the range of [(sum - 2b), (sum - b) / 2]

for each b:
    traverse over the prefix sum
    get a
    check if a is in the range
    
sum = 12
1, 2, 2, 2, 5, 0
1, 3, 5, 7, 12, 12
                 b
[1][11][0]
range: [12, 6] x

[3][7][0]

...

[1][6][5]
range: [2, 3] x

[3][][5] ++cnt

*/
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<int> preSum(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        
        int sum = preSum[n - 1];
        int cnt = 0;
        
        int sufSum = 0;
        for (int i = n - 1; i >= 2; --i) { // b
            sufSum += nums[i];
            int b_cnt = f(preSum, i - 1, sum - 2 * sufSum, (sum - sufSum) / 2);
            cnt = (cnt + b_cnt) % mod;
        }
        return cnt;
    }
    
    int f(vector<int> &preSum, int idx, int low, int high) {
        if (low > high)
            return 0;
        
        auto l_itr = lower_bound(preSum.begin(), preSum.begin() + idx, low);
        auto r_itr = upper_bound(preSum.begin(), preSum.begin() + idx, high);
        return (r_itr - l_itr);
    }
};