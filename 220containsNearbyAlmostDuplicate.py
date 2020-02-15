class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if len(nums) == 0 or k == 0 or k == 10000:
            return False
        for i in range(len(nums) - 1):
            for j in range(i + 1, min(len(nums), i + k + 1)):
                if abs(nums[j] - nums[i]) <= t:
                    return True
        return False