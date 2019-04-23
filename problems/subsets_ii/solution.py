class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        pos = 0
        path = []
        # sort it first
        nums = sorted(nums)
        self.dfs(result, [], nums, pos)
        return result
    
    def dfs(self, result, path, nums, pos):
        result.append(path)
        for i in range(pos, len(nums)):
            # check for duplicates
            if i > pos and nums[i] == nums[i-1]:
                continue
            self.dfs(result, path + [nums[i]], nums, i+1)
        