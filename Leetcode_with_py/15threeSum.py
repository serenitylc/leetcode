class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        i = 0
        for i in range(len(nums)):
            if i == 0 or nums[i] > nums[i-1]:
                l = i + 1
                r = len(nums) - 1
                while l < r:
                    s = nums[i] + nums[l] + nums[r]
                    if s == 0:
                        res.append([nums[i], nums[l], nums[r]])
                        l += 1
                        r -= 1
                        while l < r and nums[l] == nums[l-1]:
                            l += 1
                        while l < r and nums[r] == nums[r+1]:
                            r -= 1
                    elif s > 0:
                        r -= 1
                    else:
                        l += 1
        return res

# 1.将数组排序
# 2.定义三个指针，i，j，k。
# 遍历i，问题转化为在i之后的数组中寻找nums[j]+nums[k]=-nums[i]，即将三数之和问题转变为二数之和（使用双指针）