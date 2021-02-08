/*
4, 14, 2
all possible pairs:
(4, 14), (4, 2), (14, 2)
O(n^2)

0 1 0 0
1 1 1 0
0 0 1 0

1 2 2 0
c2_1 * c1_1 = 2
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> cnt(32, 0);
        for (int num : nums) {
            // check each bit
            int i = 0;
            while (num > 0) {
                cnt[i] += (num & 1);
                num = num >> 1;
                ++i;
            }
        }
        
        for (int k : cnt) {
            res += k * (n - k);
        }
        return res;
    }
};