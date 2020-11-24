/*
nums size = n
k
find a contiguous subarray
1) its length >= k, 
2) it has max avg value

return this value
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // binary search
        double left, right, mid;
        left = right = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            left = min(left, double(nums[i]));
            right = max(right, double(nums[i]));
        }
        
        // binary search
        while (left + 1e-5 < right) {
            mid = (left + right) / 2;
            if (canFind(nums, k, mid)) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    
    bool canFind(vector<int>& nums, int k, double avg) {
        double rightSum = 0, leftSum = 0, minLeftSum = 0;
        int i;
        
        for (i = 0; i < k; ++i) {
            rightSum += nums[i] - avg;
        }
        
        for (i = k; i <= nums.size(); ++i) {
            if (rightSum - minLeftSum >= 0) {
                return true;
            }
            
            if (i < nums.size()) {
                rightSum += nums[i] - avg;
                leftSum += nums[i - k] - avg;
                minLeftSum = min(minLeftSum, leftSum);
            }
        }
        return false;
    }
};