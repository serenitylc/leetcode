class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        n = len(nums)
        res = []

        def backtrace(nums, tmp_list, pos):
            if pos == n and tmp_list not in res:
                res.append(tmp_list)
            for i in range(len(nums)):
                backtrace(nums[:i] + nums[i+1:], tmp_list + [nums[i]], pos + 1)
        backtrace(nums, [], 0)
        return res
