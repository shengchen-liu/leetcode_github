/*
1, 2, 3, 4
left to right, for elem i, find the product up until elem i -1 ([0, i-1])
arr_l[1, 1, 1*2, 1*2*3]

right to left, for elem i find the product up until elem i -1 ([i + 1, n- 1])
arr_r[1*4*3*2, 1*4*3, 1*4 , 1]

res: arr_l * arr_r for each ele i
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p_l(n, 1);
        vector<int> p_r(n, 1);
        vector<int> res(n, 1);
        
        for (int i = 1; i < n; ++i) {
            p_l[i] = p_l[i - 1] * nums[i - 1];
        }
        
        for (int i = n - 2; i >= 0; --i) {  // 2
            p_r[i] = p_r[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < n; ++i) {
            res[i] = p_l[i] * p_r[i];
        }
        return res;
    }
};