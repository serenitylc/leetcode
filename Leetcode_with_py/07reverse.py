class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==0:
            return 0
        str_x = str(x)
        x = ''
        if str_x[0] == '-':
            x += '-'
        x += str_x[::-1].lstrip("0").rstrip("-")
        x = int(x)
        if -2**31<x<2**31-1:  # 反转后整数溢出返回 0
            return x
        return 0