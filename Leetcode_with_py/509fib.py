class Solution(object):
    def fib(self, N):
        memo = [0, 1]
        for i in range(N-1):
            memo.append(memo[-1] + memo[-2])
        return memo[N]