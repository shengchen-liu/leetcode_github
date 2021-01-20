/*
1, 1, 1, 2, 2, 3
1: 3
2: 2
3: 1
sorted in ascending order
i: the last good num
j: fast pointer
cnt



*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 2 || num > nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};