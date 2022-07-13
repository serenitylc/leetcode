class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        i1 = 1
        i2 = 2
        if n == 1:
            return i1
        for i in range(3, n+1):
            temp = i1 + i2
            i1 = i2
            i2 = temp
        return i2

# dp[i] = dp[i-1] + dp[i-2]:
# 第i次上楼梯方法数 = 第i-1次上楼梯方法数（再走一步） + 第i-2次上楼梯方法数（再走两步）