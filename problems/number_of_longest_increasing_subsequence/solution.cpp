/*
LIS(A[0...n-1]) := len of LIS ends with A[n-1]
LIS(A[0...n-1]) = max(LIS(A[0...i])) + 1, 0 <=i < n -1, if A[n-1] > A[j]

NLIS'(A[0...n-1]) := number of LIS ends with A[n-1]
NLIS'(A[0...n-1]) := sum(NLIS(A[0...i])), 0 <= i < n-1, s.t. A[n-1] > A[i]

      1, 3, 5, 4, 7
LIS   1  2  3  3  4
NLIS  1  1  1  1  2
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0;
        int maxLen = 0;
        int n = nums.size();
        vector<int> len(n, 1); // len of LIS ending with nums[i]
        vector<int> cnt(n, 1); // number of LIS ending with nums[i]

        // find the len of LIS
        for (int i = 1; i < n; ++i) {
           for (int j = 0; j < i; ++j) {
               if (nums[i] > nums[j]) {
                   if (len[j] + 1 > len[i]) {
                       // update len[i]
                       len[i] = len[j] + 1;
                       cnt[i] = cnt[j];
                   } else if (len[j] + 1 == len[i]) {
                       cnt[i] += cnt[j];
                   }
               }
           }
        }

        maxLen = *max_element(len.begin(), len.end());
        for (int i = 0; i < n; ++i) {
            if (len[i] == maxLen)
                res += cnt[i];
        }
        
        return res;
    }
};