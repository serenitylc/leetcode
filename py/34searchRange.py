class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def find_left_index(nums, target):
            low, high = 0, len(nums) - 1
            while low < high:
                mid = low + (high - low) // 2
                if nums[mid] > target or target == nums[mid]:
                    high = mid
                else:
                    low = mid + 1
            return low if nums and nums[low] == target else -1

        def find_right_index(nums, target):
            low, high = 0, len(nums) - 1
            while low < high:
                mid = low + (high - low) // 2 + 1
                if nums[mid] < target or target == nums[mid]:
                    low = mid
                else:
                    high = mid - 1
            return low if nums and nums[low] == target else -1

        return [find_left_index(nums, target), find_right_index(nums, target)]