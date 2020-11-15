/*
[1,1,{4,2},3]
total : sum of total array: 11
max opts sum subarray == total - x  : 11- 5 = 6
sliding window

2 ptrs: i, j
1, 1, 4, 2, 3        sum           max_len
ij                   1 < 6
i  j                 2 <6
i     j              6 == 6        j - i +1 = 3
   i  j              5 <6
   i      j          7 > 5
      i   j          6== 6         2 vs max_len(3) => 3
      ..
      ...
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // find longest substr that sums to total - x
        int n = nums.size();
        int total = 0;
        for (int num : nums) 
            total += num;  //11
        
        int j = 0;
        int sum = 0;
        int max_size = -1;
        for (int i = 0; i < n; ++i) {
            while (j < n && sum < total - x) {
                sum += nums[j];
                ++j;
            }
            if (sum == total - x) {
                // cout << i << "," << j << endl;
                max_size = max(max_size, j - i);
            }
            // move i
            sum -= nums[i];
        }
        
        return max_size != -1 ? n - max_size : -1;
    }
};