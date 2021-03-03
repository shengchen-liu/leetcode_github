/*
sort
n = 4
0  1  2  3
1, 2, 2, 4
l  m     r
m = 0 + (3 - 0) / 2 = 1
nums[m] vs. m + 1
1. == : l = m
2. <  : r = m
find the repetition number



*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int dup = -1;
        int missing = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1])
                dup = nums[i];
            else if (nums[i] > nums[i - 1] + 1)
                missing = nums[i - 1] + 1;
        }
        vector<int> res;
        res.push_back(dup);
        if (nums[n - 1] != n)
            res.push_back(n);
        else 
            res.push_back(missing);
        return res;
    }
};