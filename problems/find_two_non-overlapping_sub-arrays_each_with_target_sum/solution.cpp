/*
arr, target
two non-overlapping sub-array. each sum == target.  sum of two lens is min
eg:
arr = [3,2,2,4,3], target = 3
[3], [3]. sum_len = 2

arr = [7,3,4,7], target = 7
[7], [3,4], [7]  min_sum_len = 2

i, j ptr
7, 3, 4, 7         sum     len heap
ij                 7       [1]
   ij              3       
   i  j            7       [1, 2]
         ij        7       [1, 1, 2]
         
7, 1, 1, 1, 1, 1, 1, 1, 6    sum    len
ij                           7      [1]
   ij                        1 
   i  j                      2
   i     j                   3
   i        j                4
   i           j             5
   i              j          6
   i                 j       7
                     i  j    7
len max heap
dp: two subarrays with min lens
case 1: new subarray only contains arr[i]: check arr[i] == target ? push 1 to lens : do nothing
case 2: new subarray involves previous elements:
        for j = i -1 to 0:
            if (preSum[i] - preSum[j] == target):
                push(i - j) to lens
                break
return len[0] + len[1]

pre-fix sum:
idx     0, 1, 2, 3, 4, 5, 6, 7, 8
        7, 1, 1, 1, 1, 1, 1, 1, 5
preSum  7  8  9  10 11 12 13 14 15 
                             j  i            
2 tasks:
task1: find non-overlapping sub arrays that sum == target
task2: minimize sum of two lens

*/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int N = arr.size(), INF = 1e9;
        // dp[i] means minSumOfLengths for arr[0…i]
        vector<int> dp(N, INF);
        int sum = 0, ans = INF;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            sum += arr[hi];
            while (sum > target) {
                sum -= arr[lo++];
            }
            // win found: dp[hi]=min(hi-lo+1, dp[hi-1])
            // not found: dp[hi]=dp[hi-1]
            if (sum == target) {
                int len = hi - lo + 1;
                dp[hi] = len;
                if (lo > 0) ans = min(ans, len + dp[lo-1]);
            }
            if (hi > 0) dp[hi] = min(dp[hi], dp[hi-1]);
        }
        return ans == INF ? -1 : ans;
    }
};