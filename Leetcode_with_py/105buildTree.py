# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        rootVal = preorder.pop(0)
        root = TreeNode(rootVal)
        idx = inorder.index(rootVal)
        root.left = self.buildTree(preorder[:idx], inorder[:idx])
        root.right = self.buildTree(preorder[idx:], inorder[idx + 1:])
        return root