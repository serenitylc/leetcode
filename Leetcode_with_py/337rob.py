# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def __init__(self):
        self.memo = {}

    def rob(self, root):
        if not root:
            return 0
        if root in self.memo:
            return self.memo[root]

        self.memo[root] = max(self.rob(root.left) + self.rob(root.right), \
        root.val + (0 if not root.left else self.rob(root.left.left) + self.rob(root.left.right)) + \
                    (0 if not root.right else self.rob(root.right.left) + self.rob(root.right.right)))
                    
        return self.memo[root]
