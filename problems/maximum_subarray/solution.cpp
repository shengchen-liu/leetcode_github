/*
divide and conquer
max of :
1) max subarrray contains only left side
2) max subarray contains only right side
3) max subarray contains both sides

dfs(left, right): returns the max sum of the subarray [left ... right]
mid  = left + (r - l) / 2
1) leftMax = dfs(left, mid)
2) rightMax = dfs(mid + 1, right)
3) midSum
bestLeftSum = 0
for (i = mid - 1 to left):
    cur += nums[i]
    bestLeftSum += max(bestLeftSum, cur)

bestRightSum = 0
for (i = mid + 1 to right):
    cur += nums[i]
    bestRightSum += max(bestRightSum, cur)
midSum = nums[mid] + bestLeftSum + bestRightSum

return max(1), 2), 3))
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = dfs(0, n - 1, nums);
        return res;
    }

    int dfs(int left, int right, vector<int>& nums) {
        // termination
        if (left > right)
            return INT_MIN;

        // recursion
        int mid = left + (right - left) / 2;
        int leftMaxSum = dfs(left, mid - 1, nums);
        int rightMaxSum = dfs(mid + 1, right, nums);

        int cur = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        
        for (int i = mid - 1; i >= left; --i) {
            cur += nums[i];
            bestLeftSum = max(bestLeftSum, cur);
        }

        cur = 0;
        for (int i = mid + 1; i <= right; ++i) {
            cur += nums[i];
            bestRightSum = max(bestRightSum, cur);        
        }

        int bestMidSum = bestLeftSum + nums[mid] + bestRightSum;
        return max(max(leftMaxSum, rightMaxSum), bestMidSum);
    }
};