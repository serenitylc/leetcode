# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack, ret = [], []
        cur = root
        while stack or cur:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                ret.append(cur.val)
                cur = cur.right
        return ret

# ตÝน้
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        if root:
            ret += self.inorderTraversal(root.left)
            ret.append(root.val)
            ret += self.inorderTraversal(root.right)
        return ret