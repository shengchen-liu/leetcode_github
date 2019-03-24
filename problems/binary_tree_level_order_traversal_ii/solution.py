# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        results = []
        if root == None:
            return results
        
        # build a queue 
        q = [root]
        
        while len(q) != 0:
            # each layer
            size = len(q)
            layer_result = []
            for i in range(size):
                # deque
                u = q.pop(0)
                layer_result.append(u.val)
                if (u.left != None):
                    q.append(u.left)
                if (u.right != None):
                    q.append(u.right)                    
            results.append(layer_result)
        results.reverse()
        return results
                    
                
        
        