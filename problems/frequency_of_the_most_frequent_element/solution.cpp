/*
 nums = [1,2,4], k = 5
 k  nums     res
 3  1  2  4  1
 2  2  2  4  2
 0  3  3  4  2
 
 nums = [1,4,4,5,13], k = 5
 k  nums        res 
 2  1 4 4 5 13  2
 0  1 5 5 5 13  3

pick the num that has the most frequencies
len = this num's freq
if len <= k:
    all num++
    k -= len

max heap: {freq, num}
e.g.
2: 4 ->
1: 1
1: 5
1: 13

hashmap : {num : freq}
1: 1      1: 1
4: 2 *  =>5: 3
5: 1      13:1
13 : 1
 
for freq from 1 to n:
    cur_freq = freqs[freq] + # of digits that can reach to freq
    res = max(res, cure_freq)
return res
*/


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i = 0, j;
        long K = (long) k;
        sort(nums.begin(), nums.end());
        for (j = 0; j < nums.size(); ++j) {
            K += nums[j];
            if (K < (long)nums[j] * (j - i + 1))
                K -= nums[i++];
        }
        return j - i;
    }
};