class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        '''
        in_degree
        0 <- {}
        1 <- {0}
        2 <- {1,3}
        3 <- {0, 4}
        4 <- {}
        
        '''
        
        '''
        out_degree
        0 -> {1, 3}
        1 -> {2}
        2 -> {}
        3 -> {2}
        4 -> {3}
        '''
        in_degree = {i: set() for i in range(numCourses)}
        out_degree = {i: set() for i in range(numCourses)}
        for i, j in prerequisites:
            in_degree[i].add(j)
            out_degree[j].add(i)
            
        # all nodes with 0 in_degree
        queue = [node for node in in_degree if len(in_degree[node])==0]
        while queue:
            node = queue.pop(0)
            for neigh in out_degree[node]:# 1, 3; 2
                in_degree[neigh].remove(node)
                if len(in_degree[neigh]) == 0:
                    queue.append(neigh) 
                    # node = 0, queue = [1]
                    # node = 1, queue = []
            in_degree.pop(node)
        return not in_degree  # if there is cycle, forward won't be None

            
        
        
        