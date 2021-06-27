/*
nums = [5,6,2,7,4]
w,x : top 2 largest 
y,z : top 2 smallest
*/
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int a = nums[0];
        int b = nums[1];
        int c = nums[n - 1];
        int d = nums[n - 2];
        return c * d - a  * b;
    }
};