class Solution {
public:
    int rob(vector<int>& nums) {
         int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        vector<int> L(size,0),R(size,0);
        L[1] = nums[0];
        R[1] = nums[1];
        for (int i = 2;i < size;i++) {
            //递推公式，注意nums中数的顺序先后
            L[i] = max(L[i - 2] + nums[i - 1],L[i - 1]);
            R[i] = max(R[i - 2] + nums[i],  R[i - 1]);
        }
        return max(L[size - 1],R[size - 1]);//取较大值
    }
};