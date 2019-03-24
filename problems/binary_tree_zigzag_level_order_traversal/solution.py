# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res, queue = [], [(root, 0)]
        while queue:
            curr, level = queue.pop(0)
            if curr:
                if len(res) < level+1:
                    res.append([])
                if level % 2 == 0:
                    res[level].append(curr.val)
                else:
                    res[level].insert(0, curr.val)
                queue.append((curr.left, level+1))
                queue.append((curr.right, level+1))
        return res

        