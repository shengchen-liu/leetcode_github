class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if len(nums) == 0:
            return False
        left, right = 0, len(nums) - 1
        while left < right and nums[left] == nums[right]:       # to distinguish left ascending array and right ascending array
            left += 1

        while left + 1 < right:
            mid = left + (right - left) // 2
            if nums[left] <= nums[mid]:                         # nums[mid] at left ascending array
                if nums[left] <= target < nums[mid]:
                    right = mid
                else:                                           # nums[mid] < target
                    left = mid
            elif nums[mid] <= nums[right]:                      # nums[mid] at right ascending array
                if nums[mid] < target <= nums[right]:
                    left = mid 
                else:                                           # nums[mid] > target
                    right = mid 
                    
        if nums[left] == target or nums[right] == target:
            return True
        return False