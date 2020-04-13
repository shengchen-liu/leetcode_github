class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int start = 0;
        int end = nums.size() - 1;
        int first = -1;
        int last = -1;
        // first position
        while (start + 1 < end) {
            int mid = start + (end - start) / 2; // 2, 3
            if (nums[mid] >= target) {  // 8 vs 8
                end = mid; // end: 3
            }
            else start = mid; // start: 2
        }
        if (nums[start] == target) first = start;
        else if (nums[end] == target) first = end;
        
        //last position
        start = 0;
        end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2; //mid: 2, 3, 4
            if (nums[mid] <= target) {
                start = mid; // start : 2, 3, 4
            }
            else end = mid;
        }
        if (nums[end] == target) last = end;
        else if (nums[start] == target) last = start;
        
        return {first, last};
    }
};