/*
Arithmetic Subarrays
1, 3, 5, 7, 9
s[i+1] - s[i] == s[1] - s[0]
vector<int> nums: {4,6,5,9,3,7}
l size of m : [0,0,2]
r size of m : [2,3,5]
for i = 0 ~ m -1
    query  range [l[i], r[i]] -> get a subarray from nums
    determine if this rearranged subarray is Arithmetic Subarrays
[bool, bool, ....] m

i = 0 => l[i] : 0, r[i]: 2 => subarray {4, 6, 5}
nums[0], nums[1], nums[2]

i = 1 => l[1] : 0, r[1]: 3 => subarray {4, 6, 5, 9}
nums[0], nums[1], nums[2], nums[3]

1.
define a fuction to check if a subarray is Arithmetic
    s[i+1] - s[i] == s[1] - s[0]

2.
iterate i from 0 to m-1:
    check if subarray is Arithmetic
    append to result
    
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        int n = nums.size();
        vector<bool> res(m, false);
        for (int i = 0; i < m; ++i) {
            int begin = l[i];
            int end = r[i];
            res[i] = checkArithmetic(nums, begin, end);
        }
        return res;
        
    }
    
    // define a fuction to check if a subarray is Arithmetic
    bool checkArithmetic(vector<int> &nums, int begin, int end) {
        int n = end - begin + 1;
        
        vector<int> s(nums.begin() + begin, nums.begin() + end + 1); 
        
        // sort
        // {4, 6, 5} => {4, 5, 6}
        sort(s.begin(), s.end());
        
        // s[i+1] - s[i] == s[1] - s[0]
        for (int i = 0; i < n - 1; ++i) {
            if (s[i+1] - s[i] != s[1] - s[0]) return false;
        }
        
        return true;
    }
};