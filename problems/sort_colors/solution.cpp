/*
000, 111, 2222
2,0,2,1,1,0
ptrs: i, j, cur
i: nums to the left are 0s
j: nums to the right are 2s
cur: 
1. nums[cur] == 0, swap nums[i++], nums[cur]
2. nums[cur] == 2, swap nums[j--], nums[cur]
3. nums[cur] == 1, ++cur
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int cur = 0;
        while (cur <= j) {
            // 1. nums[cur] == 0, swap nums[i++], nums[cur]
            if (nums[cur] == 0){
                swap(nums[i++], nums[cur++]);
            } else if (nums[cur] == 2){
                swap(nums[j--], nums[cur]);
            }
            else cur++;
        }
    }
};