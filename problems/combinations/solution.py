class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        '''
        n=4, k=2
        1,2
        1,3
        1,4
        2,3
        2,4
        3,4
        
        [] -> [1] -> [1,2]; [1,3]; [1,4]
        [] -> [2] -> [2,3]; [2,4];
        [] -> [3] -> [3,4]
        
        [1,2,3,4]
        '''
        result = []
        pos = 0
        layer = 0
        path = []
        self.dfs(result, path, pos, layer, n, k)
        return result
    
    def dfs(self, result, path, pos, layer, n, k):
        # print(layer)
        if layer == k:
            result.append(path)
            # print(path)
        else: 
            layer += 1
            for i in range(pos, n): # 0,1,2,3
                value = i+1
                self.dfs(result, path + [value], i+1, layer, n, k)
            