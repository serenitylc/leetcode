class Solution(object):
    def rob(self, nums):
        n = len(nums)
        if n == 1:
            return nums[0]
        return max(self.robRange(nums, 0, n - 2), self.robRange(nums, 1, n - 1))

    def robRange(self, nums, start, end):
        dp_i, dp_i_1, dp_i_2 = 0, 0, 0
        for i in range(end, start - 1, -1):
            dp_i = max(dp_i_1, dp_i_2 + nums[i])
            dp_i_2 = dp_i_1
            dp_i_1 = dp_i
        return dp_i

