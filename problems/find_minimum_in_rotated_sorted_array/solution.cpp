class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            // no rotation
            if (nums[left] < nums[right]) return nums[left];
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) left = mid;
            else right = mid;
        }
        return nums[left] < nums[right] ? nums[left] : nums[right];
    }
};