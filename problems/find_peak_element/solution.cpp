class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) { // peak on the left side of mid
                right = mid;
            } else left = mid;
        }
        return nums[right] > nums[left] ? right : left;
    }
};