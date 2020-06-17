class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left + 1 < right) {
            // if there is no rotation
            if (nums[right] > nums[left]) return nums[left];
            
            int mid = left + (right - left) / 2;
            // ascending
            if (nums[mid] > nums[left]) {
                left = mid;            
            } else {
                right = mid;
            }
        }
        if (nums[left] < nums[right]) return nums[left];
        else return nums[right];
    }
};