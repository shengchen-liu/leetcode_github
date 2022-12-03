/*
nums = [4,5,6,7,0,1,2], target=0.  return 4
    
      7
    6
  5
              3
            2
          1
        0

check rotated in range [start, end]:
nums[start] > nums[end] == true
mid = start + (end - start) / 2

1. nums[start] < nums[mid] => no rotated
    a. nums[start] < target < nums[mid] < : end = mid
    b. else: star = mid

2. nums[start] > nums[mid] => rotated
    a. nums[mid] < target < nums[end] : start = mid
    b. else: end = mid
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid])
                    end = mid;
                else 
                    start = mid;
            } else {
                if (nums[mid] < target && target <= nums[end])
                    start = mid;
                else 
                    end = mid;
            }
        }

        if (nums[start] == target)
            return start;
        if (nums[end] == target)
            return end;
        return -1;
    }
};