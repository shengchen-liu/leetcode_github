# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        result = []
        if root == None:
            return result
        # queue
        queue = []
        queue.append(root)
        
        # traverse
        while (len(queue) != 0):
            size = len(queue)
            for i in range(size):
                head = queue.pop(0)
                if head:
                    queue.append(head.left)
                    queue.append(head.right)
                    result.append(str(head.val))
                else:
                    result.append('null')
                    
                # print(result)
        return ','.join(result)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0:
            return None
        nodes = data.split(',')
        root_node = TreeNode(int(nodes[0]))
        queue = []
        queue.append(root_node)
        cur_pos = 1
        while len(queue) > 0:
            cur = queue.pop(0)
            if nodes[cur_pos] != 'null':
                cur.left = TreeNode(int(nodes[cur_pos]))
                queue.append(cur.left)
            cur_pos += 1
            if nodes[cur_pos] != 'null':
                cur.right = TreeNode(int(nodes[cur_pos]))
                queue.append(cur.right)
            cur_pos += 1
        return root_node
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))