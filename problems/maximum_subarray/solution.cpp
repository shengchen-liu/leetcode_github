// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int res = INT_MIN;
//         int curSum = 0;
//         for (int num : nums){
//             curSum = max(curSum + num, num);
//             res = max(res, curSum);
//         }
//         return res;
//     }
    
// };
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    int crossSum(vector<int>& nums, int left, int right, int p){
        if (left == right) return nums[left];
        
        int leftSubsum = INT_MIN;
        int currSum = 0;
        for (int i = p; i > left - 1; --i){
            currSum += nums[i];
            leftSubsum = max(leftSubsum, currSum);
        }
        
        int rightSubsum = INT_MIN;
        currSum = 0;
        for (int i = p + 1; i < right +1; ++i){
            currSum += nums[i];
            rightSubsum = max(rightSubsum, currSum);
        }
        
        
        return leftSubsum + rightSubsum;
    }
    
    int helper(vector<int>& nums, int left, int right){
        if (left == right) return nums[left];
        
        int p = (left + right) / 2;
        
        int leftSum = helper(nums, left, p);
        int rightSum = helper(nums, p + 1, right);
        int cross = crossSum(nums, left, right, p);
        
        return max(max(leftSum, rightSum), cross);
    }
    
};
