/*
if nums[mid] == target => return mid
if nums[start] < nums[mid]: 
    1) nums[start] <= target <= nums[mid] => end = mid
    2) else: start = mid
if nums[start] < nums[mid]:
    1) nums[mid] <= target <= nums[end] => start = mid
    2) else: end = mid
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) end = mid;
                else start = mid;
            } else {
                if (nums[mid] < target && target <= nums[end]) start = mid;
                else end = mid;
            }
        }
        if (nums[start] == target) return start;
        else if (nums[end] == target) return end;
        else return -1;
    }
};