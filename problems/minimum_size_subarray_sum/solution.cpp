/*
2, 3, 1, 2, 4, 3   sum   len
ij                  2
i  j                5
i     j             6    3
i        j          8    4*
   i     j          6    3 
   i        j       10   4
      i     j       7    3*
      i        j    10   4
         i     j    9    3
            i  j    7    2



*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int sum = 0;  // i to j sum
        int res = INT_MAX;
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum >= target) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                ++i;
            }
        }
        return res == INT_MAX? 0 : res;
    }
};