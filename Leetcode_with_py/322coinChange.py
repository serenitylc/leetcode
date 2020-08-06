class Solution(object):
    def coinChange(self, coins, amount):
        memo = {}
        def dp(n):
            if n == 0:
                return 0
            if n < 0:
                return -1
            if n in memo:
                return memo[n]
            res = float('INF')
            for coin in coins:
                subproblem = dp(n - coin)
                if subproblem == -1:
                    continue
                res = min(res, 1 + subproblem)
            memo[n] = res if res != float('INF') else -1
            return memo[n]
        return dp(amount)