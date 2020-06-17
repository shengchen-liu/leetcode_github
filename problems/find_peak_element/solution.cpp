class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1]) { // peak on the right
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[left] > nums[right]) return left;
        else return right;
    }
};