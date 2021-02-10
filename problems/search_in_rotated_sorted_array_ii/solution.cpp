/*
0  1  2  3  4  5  6
2, 5, 6, 0, 0, 1, 2      l     r    m
l        m        r      0     6    3
m = 0 + (6 - 0) / 2= 3
   *m
 *
*   
       *
     *
     
  *   
* 
        *
      *
    *m
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] == nums[right])
                ++left;
            else 
                break;
        }
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] == target || nums[right] == target || nums[mid] == target)
                return true;
            if (nums[left] <= nums[mid]) {
                if (nums[left] < target && target < nums[mid])
                    right = mid;
                else 
                    left = mid;
            } else {
                if (nums[mid] < target && target < nums[right])
                    left = mid;
                else 
                    right = mid;
            } 
        }
                    
        if (nums[left] == target || nums[right] == target)
            return true;
        return false;
    }
};