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
            if i==0 or nums[i]>nums[i-1]:
                l = i + 1
                r = len(nums) - 1
                while l < r:
                    s = nums[i] + nums[l] + nums[r]
                    if s==0:
                        res.append([nums[i], nums[l], nums[r]])
                        l += 1
                        r -= 1
                        while l < r and nums[l]==nums[l-1]:
                            l += 1
                        while l < r and nums[r]==nums[r+1]:
                            r -= 1
                    elif s > 0:
                        r -= 1
                    else:
                        l += 1
        return res

# 1.���������� 
# 2.��������ָ�룬i��j��k��
# ����i������ת��Ϊ��i֮���������Ѱ��nums[j]+nums[k]=-nums[i]����������֮������ת��Ϊ����֮�ͣ�ʹ��˫ָ�룩