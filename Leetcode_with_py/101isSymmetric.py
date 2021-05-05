# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isMirror(p1, p2):
            if not p1 and not p2:
                return True
            elif not p1 or not p2:
                return False
            if p1.val != p2.val:
                return False
            return isMirror(p1.left, p2.right) and isMirror(p1.right, p2.left)
        return isMirror(root, root)

# Python 迭代：层序遍历，然后检查每一层是不是回文数组
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root : TreeNode
        :rtype: bool
        """
        queue = [root]
        while (queue):
            next_queue = list()
            layer = list()
            for node in queue:
                if not node:
                    layer.append(None)
                    continue
                next_queue.append(node.left)
                next_queue.append(node.right)
                layer.append(node.val)
            if layer != layer[::-1]:
                return False
            queue = next_queue
        return True

