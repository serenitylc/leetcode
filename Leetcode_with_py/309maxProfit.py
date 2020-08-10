class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n <= 1:
            return 0
        dp_i_0, dp_i_1 = 0, float("-inf")  # base (i = -1)
        dp_pre_0 = 0  # i = -2
        for i in range(n):
            temp = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i])
            dp_pre_0 = temp
        return dp_i_0

# k = +infinity with cooldown:
# dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
# dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
# 解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。