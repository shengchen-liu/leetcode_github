/*
check rotated in range [start, mid]:
nums[start] > nums[mid] == true
mid = start + (end - start) / 2

1. nums[start] <= nums[mid] => no rotated
    a. nums[start] <= target < nums[mid] < : end = mid
    b. else: star = mid

2. nums[start] > nums[mid] => rotated
    a. nums[mid] < target < nums[end] : start = mid
    b. else: end = mid

*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start  + (end -  start) / 2;
            if (nums[mid] == target) return true; 
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                ++start;
                --end;
            } else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid])
                    end = mid;
                else 
                    start = mid;
            } else {
                if (nums[mid] < target && target <= nums[end])
                    start = mid;
                else end = mid;
            }
        }
        if (nums[start] == target || nums[end] == target)
            return true;
        return false;
    }
};