# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        result = []
        if root == None:
            return result
        # queue
        queue = []
        queue.append(root)
        layer_num = 0
        while len(queue)!= 0:
            size = len(queue)
            
            # 1,3, 5, ...: right -> left
            layer = []
             
            for i in range(size):
                head = queue.pop(0)
                if head.left:
                    queue.append(head.left)
                if head.right:
                    queue.append(head.right)
                # odd or even
                # even: 0,2,4,...: left -> right
                if layer_num %2 ==0:
                    layer.append(head.val)
                else: # odd
                    layer.insert(0, head.val)
            result.append(layer)
            layer_num += 1    
        return result
        