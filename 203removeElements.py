# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head != None and val == head.val:
            head=head.next
        if head==None:
            return None
        else:
            node = head
            while node.next != None:
                if node.next.val==val:
                    node.next = node.next.next
                else:
                    node=node.next
            return head