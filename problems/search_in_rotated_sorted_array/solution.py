class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        start = 0
        end = len(nums) - 1
        while(start + 1 < end):
            mid = int(start + (end - start)/2)
            if nums[mid] == target:
                return mid
            if nums[start] < nums[mid]:
                # situation 1
                if nums[start] <= target and target <= nums[mid]:
                    end = mid
                else:
                    start = mid
            else:
                # situation 2
                if nums[mid] <= target and target <= nums[end]:
                    start = mid
                else:
                    end = mid
       
        if nums[start] == target:
            return start
        elif nums[end] == target:
            return end
        else:
            return -1
                
        