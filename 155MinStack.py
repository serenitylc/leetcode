class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.val = []
        self.index = -1
        
    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.val.append(x)
        self.index += 1

    def pop(self):
        """
        :rtype: None
        """
        self.val.pop()
        self.index -= 1

    def top(self):
        """
        :rtype: int
        """
        return self.val[self.index]

    def getMin(self):
        """
        :rtype: int
        """
        return min(self.val)
        
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()