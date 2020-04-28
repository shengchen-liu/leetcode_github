/*
for each element e:
    find the longest window starting with e that satisfy the criteria. The size of the window is L_e.  If the tail of the window is the last element: stop
    
    
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int res = 0, prod = 1, left = 0;
    for (int i = 0; i < nums.size(); ++i) {
        prod *= nums[i];
        while (prod >= k) prod /= nums[left++];
        res += i - left + 1;
    }
    return res;
    }
};