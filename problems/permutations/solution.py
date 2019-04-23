class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        '''
        [1, 2, 3]
        
        [] -> [1] -> [1,2] -> [1,2,3]
        [] -> [1] -> [1,3] -> [1,3,2]
        [] -> [1] -> [2,1] -> [2,1,3]
        ...
        DFS
        '''
        result = []
        path = []
        self.dfs(nums, path, result)
        return result
    
    def dfs(self, nums, path, result):
        if not nums:
            result.append(path)
        # return # backtracking
        for i in range(len(nums)):
            self.dfs(nums[:i]+nums[i+1:], path+[nums[i]], result)
