# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))


class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        queue = []
        queue.append(root)
        ans = 0
        while queue:
            ans += 1
            for i in range(len(queue)):
                node = queue.pop(0)  # 0 ≤ªø……Ÿ
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return ans