/*
10, 5, 2, 6   prod     cnt
i,j           10(T)    +1
i   j         50(T)    +2
i      j      100(F)   
    i  j      10(T)    +2
    i     j   60(T)    +3

*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1;
        int res = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right){
            prod *= nums[right];
            while (prod >= k) {
                prod = prod / nums[left];
                ++left;
            }
            res += right - left + 1;
        }
        return res;
    }
};