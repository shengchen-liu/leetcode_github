class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
			return 0;
		}
		
		int start, end, mid;
		start = 0;
		end = nums.length - 1;
		while (start + 1 < end) {
			mid = start + (end - start) / 2;
			if (nums[mid] == target) {
				end = mid;
			}
			else if (nums[mid] < target) {
				start = mid;
			}
			else if (nums[mid] > target) {
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
}