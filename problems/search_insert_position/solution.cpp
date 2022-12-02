class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        if (nums[start] == target) {
            return start;
        }
        while (start + 1 < end) {
            int mid = start + (end - start) /2;
            if (nums[mid] == target) {
                start = mid;
            }
            else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (nums[start] == target) {
			return start;
		}
		if (nums[end] == target) {
			return end;
		}
		if (nums[start] > target) {
			return start;
		}
		if (nums[start] < target && nums[end] > target) {
			return start + 1;
		}
		return end + 1; // nums[end] < target
        

    }
};