class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # 1. num of eges == n-1
        if len(edges) != n-1:
            return False
        #graph int:{}
        # 0: {1, 2, 3}
        # 1: {0, 4}
        # 2: {0}
        # 3: {0}
        # 4: {1}
        graph = {i:set() for i in range(n)}
        for x, y in edges:
            # x:0, y:1
            graph[x].add(y)
            graph[y].add(x)
        # print(graph)
        
        # 2. num of connected nodes == n
        # BFS
        # queue
        queue = [0]
        unique_nodes = set()
        while len(queue) != 0:
            # loop one line of dic
            head = queue.pop(0)
            unique_nodes.add(head)
            for node in graph[head]:
                # 1,2,3
                if node not in unique_nodes:
                    unique_nodes.add(node)
                    queue.append(node)
        return len(unique_nodes) == n
            