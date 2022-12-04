/*
nums = [1, 1, 2]
1, 1, 2
i  j
   
1, 2, 3
i
nums[i] < nums[i+1]: i++, j++, nums[j] = nums[i]
        ==           i++
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] < nums[i+1]) {
                j++;
                nums[j] = nums[i+1];
            }
        }
        return j + 1;
    }
};