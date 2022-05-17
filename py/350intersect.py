class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums = []
        for i in range(len(nums1)):
            if nums1[i] in nums2:
                nums.append(nums1[i])
                nums2.remove(nums1[i])
        return nums

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        inter = set(nums1) & set(nums2)
        res = []
        for i in inter:
            res += [i] * min(nums1.count(i), nums2.count(i))
        return res