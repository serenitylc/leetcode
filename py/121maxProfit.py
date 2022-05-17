class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1:
            return 0
        min_input, max_profit = prices[0], 0
        for price in prices[1:]:
            min_input = min(min_input, price)
            max_profit = max(max_profit, price - min_input)
        return max_profit