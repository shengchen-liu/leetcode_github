# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        result = []
        if root == None:
            return result
        queue = []
        # enqueue
        queue.append(root)
        
        while(len(queue)!=0):
            size = len(queue)
            layer = []
            for i in range(size):
                # dequeue
                head = queue.pop(0)
                if head.left != None:
                    queue.append(head.left)
                if head.right != None:
                    queue.append(head.right)
                layer.append(head.val)
        
            result.insert(0, layer)
        return result
    
        