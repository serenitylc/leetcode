class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(len(nums) < 2):
            return len(nums)
        j = 0;
        for i in range(len(nums)-1):
            if(nums[j] != nums[i+1]):
                j += 1
                nums[j] = nums[i+1]
        return j+1


# Python3:
# class Solution:
#     def removeDuplicates(self, nums: List[int]) -> int:
#         i = 0
#         for num in nums:
#             if nums[i] != num:
#                 i += 1
#                 nums[i] = num
#         return len(nums) and i+1