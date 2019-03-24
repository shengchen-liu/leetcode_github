class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if n == 1:
            return True
        if len(edges) != n - 1:
            return False
        neighbors = {i: [] for i in range(n)}
        for v, w in edges:
            neighbors[v] += w,
            neighbors[w] += v,
        queue = [0]
        nodes = set()
        for v in queue:
            neighbor_nodes = neighbors.pop(v, [])
            queue += neighbor_nodes
            nodes.update(neighbor_nodes)

        # return not neighbors
        return len(nodes) == n