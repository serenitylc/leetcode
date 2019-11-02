class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        j = 0
        for num in nums:
            if(num != val):
                nums[j] = num
                j += 1
        return j

# ÄæÐòpop
# class Solution(object):
#     def removeElement(self, nums, val):
#         """
#         :type nums: List[int]
#         :type val: int
#         :rtype: int
#         """
#         j=len(nums)
#         for i in range(j-1,-1,-1):
#             if nums[i]==val:
#                 nums.pop(i)    
#         return len(nums)