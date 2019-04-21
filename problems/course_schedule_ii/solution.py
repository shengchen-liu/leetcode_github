class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        '''
        [[1,0],[2,0],[3,1],[3,2]]
        in_graph:
        0 <- {}
        1 <- {0}
        2 <- {0}
        3 <- {1, 2}
        
        out_graph:
        0 -> {1,2}
        1 -> {3}
        2 -> {3}
        3 -> {}
        
        '''
        in_graph = {i:set() for i in range(numCourses)} #O(C)
        out_graph = {i:set() for i in range(numCourses)} # O(C)
        for x, y in prerequisites: #O(E)
            # x <- y
            in_graph[x].add(y)
            out_graph[y].add(x)
            
        # queue to store all node with 0 input
        queue = [node for node in in_graph if len(in_graph[node])==0] # O(C)
        # print(queue)
        # [0]
        # BFS
        result = []
        while queue: #O(C)
            node = queue.pop(0) # 0; 1, 2
            targets = out_graph[node] # {1,2}; {3},{3}
            for target in targets: # 2; 3, 3 O(C)
                in_graph[target].remove(node) # {}; {2}, {0}
                if len(in_graph[target]) == 0:
                    # enqueue
                    queue.append(target) # [1, 2]
            in_graph.pop(node)
            result.append(node) #[0, 1,2,3]
        # O(N)
        if in_graph:
            return []
        return result