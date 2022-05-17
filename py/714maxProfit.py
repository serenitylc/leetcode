class Solution(object):
    def maxProfit(self, prices, fee):
        n = len(prices)
        if n <= 1:
            return 0
        dp_i_0, dp_i_1 = 0, float("-inf")
        for i in range(n):
            temp = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i] - fee)
            dp_i_1 = max(dp_i_1, temp - prices[i])
        return dp_i_0