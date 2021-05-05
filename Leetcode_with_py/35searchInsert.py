class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low = 0
        high = len(nums)
        while low < high:
            mid = low + (high - low) / 2
            if nums[mid] > target:
                high = mid;
            elif nums[mid] < target:
                low = mid + 1
            else:
                return mid
        return low
