class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        '''
        [0,0]: {[0,1], [1,0]}
        [0,1]: {[0,0], [0,2], [1,1]}
        [0,2]: {[0,1], [0,2]}
        ...
        [2,2]: {[2,1]}
        '''
        # graph
        if len(grid) == 0:
            return 0
        n_rows = len(grid)
        n_cols = len(grid[0])
        count = 0
        
        for r in range(n_rows):
            for c in range(n_cols):
                if grid[r][c] == '1':
                    count += 1
                    grid[r][c] == '0' # mark as visited
                    #queue
                    neighbors = []
                    neighbors.append([r,c])
                    while neighbors:
                        head = neighbors.pop(0)
                        i = head[0]
                        j = head[1]
                        if i-1 >=0 and grid[i-1][j] == '1':
                            grid[i-1][j] = '0'
                            neighbors.append([i-1, j])
                        if i+1<=n_rows-1 and grid[i+1][j]=='1':                    
                            grid[i+1][j] = '0'
                            neighbors.append([i+1, j])
                        if j-1 >= 0 and grid[i][j-1] == '1':
                            grid[i][j-1] = '0'
                            neighbors.append([i, j-1])
                        if j +1 <=  n_cols -1 and grid[i][j+1] == '1':
                            grid[i][j+1] = '0'  
                            neighbors.append([i, j+1])
        return count
     
                