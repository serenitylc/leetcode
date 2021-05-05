"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def preorder(self, root):
        if not root:
            return []
        res, stack = [], [root]
        while stack:
            root = stack.pop()
            res.append(root.val)
            if root.children:
                for idx in range(len(root.children)-1, -1, -1):
                    stack.append(root.children[idx])
        return res

class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if not root:
            return []
        res = [root.val]
        if root.children:
            for chi in root.children:
                res.extend(self.preorder(chi))
        return res