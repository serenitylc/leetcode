class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n <= 1:
            return 0
        dp_i_k1_0, dp_i_k1_1 = 0, float("-inf")
        dp_i_k2_0, dp_i_k2_1 = 0, float("-inf")
        for i in range(n):
            dp_i_k2_0 = max(dp_i_k2_0, dp_i_k2_1 + prices[i])
            dp_i_k2_1 = max(dp_i_k2_1, dp_i_k1_0 - prices[i])
            dp_i_k1_0 = max(dp_i_k1_0, dp_i_k1_1 + prices[i])
            dp_i_k1_1 = max(dp_i_k1_1, -prices[i])
        return dp_i_k2_0