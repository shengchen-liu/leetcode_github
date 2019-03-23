# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import queue 

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        results = []
        if root == None:
            return results
        
        # define queue
        q =  queue.Queue()
        q.put(root)
        
        while not q.empty():
            size = q.qsize()
            layer_result = []
            for i in range (size):
                # dequeue
                u = q.get()
                layer_result.append(u.val)

                # get left
                if (u.left != None):
                    q.put(u.left)
                if (u.right != None):
                    q.put(u.right)
            results.append(layer_result)
                
            
        return results
            