class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(1, len(nums)):
            nums[i] = nums[i] + max(nums[i-1], 0)
        return max(nums)

# 可以理解为动态规划思想：
# nums[i-1]是到前一项为止的最大子序和
# 只要大于0，就可以相加构造最大子序和；小于0则相加为0，nums[i]=nums[i]，相当于最大子序和又重新计算。一边遍历一边计算。

