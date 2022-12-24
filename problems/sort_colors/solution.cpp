/*
2,0,2,1,1,0 
i, j
i: all nums before i are 0
j: all nums after j are 2

2, 0, 2, 1, 1, 0
i  k           j
0, 2, 2, 1, 1, 0
   i           k
0, 0, 2, 1, 1, 2
               kj

k from i to end:
    if nums[k] == 0: swap(nums[i], nums[k]), ++i
    else: ++k
k from j to 0:
    if nums[k] == 2: swap(nums[j], nums[k]), --i
    else: --k
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int k = 0;
        while (k <= j) {
            if (nums[k] == 0) {
                swap(nums[i++], nums[k++]);
            } else if (nums[k] == 2){
                swap(nums[j--], nums[k]);
            } else
                ++k;
        }
    }
};