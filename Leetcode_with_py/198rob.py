class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        dp = [nums[n-1]] * n
        for i in range(n-2, -1, -1):
            for j in range(i, n):
                dp[i] = max(dp[i], nums[j] + (dp[j+2] if j + 2 < n else 0))
        return dp[0]
