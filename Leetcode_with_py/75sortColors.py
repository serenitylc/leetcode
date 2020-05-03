class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        first = 0
        middle = 0
        last = len(nums)-1
        while middle <= last:
            if nums[middle] == 2:
                nums[middle], nums[last] = nums[last], nums[middle]
                last -= 1
            elif nums[middle] == 0:
                nums[first] = 0
                if middle > first:
                    nums[middle] = 1
                first += 1
                middle += 1
            else:
                middle += 1

class Solution(object):
    def sortColors(self, nums):
        result=[]
        res=[0 for i in range(3)]
        for i in range(len(nums)):
            res[nums[i]] += 1
        for i in range(3):
            result = result + res[i] * [i]
        nums[:]=result