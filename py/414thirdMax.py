class Solution(object):
    def thirdMax(self, nums):
        nums = set(nums)
        if len(nums) < 3:
            return max(nums)
        n1 = max(nums)
        nums.remove(n1)
        n2 = max(nums)
        nums.remove(n2)
        return max(nums)