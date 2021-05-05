class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        length = len(piles)
        dp = [[0] * length for _ in range(length)]
        for i, pile in enumerate(piles):
            dp[i][i] = pile
        for i in range(length - 2, -1, -1):
            for j in range(i + 1, length):
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
        return dp[0][length - 1] > 0

class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        length = len(piles)
        dp = [0] * length
        for i, pile in enumerate(piles):
            dp[i] = pile
        for i in range(length - 2, -1, -1):
            for j in range(i + 1, length):
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1])
        return dp[length - 1] > 0

