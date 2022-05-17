# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        a = head
        b = head
        for i in range(n):
            if a.next:
                a = a.next
            else:
                return head.next    # [1] 1 ==> []
        while a.next:
            a = a.next
            b = b.next
        b.next = b.next.next
        return head