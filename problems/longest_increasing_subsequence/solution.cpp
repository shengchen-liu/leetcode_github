/*
10,9,2,5,3,7,101,18

LI(i) : length of the longest subseq that ends at nums[i]
for j 0 to i-1:
    if (nums[j] < nums[i]):
        len[i] = max(len[j]) + 1
10, 9, 2, 5, 3, 7, 101, 18
1   1  1  2  2  3  4    4

*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        vector<int> len(n, 1);
        if (n == 1)
            return 1;
        for (int i = 1; i < n; ++i) {
            int tmp = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    tmp = max(tmp, len[j] + 1);
                }
            }
            len[i] = tmp;
        }
        for (int i = 0; i < n; ++i) {
            res = max(res, len[i]);
        }
        return res;
    }
};