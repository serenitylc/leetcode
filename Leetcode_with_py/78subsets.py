class Solution(object):
    def subsets(self, nums):
        res = [[]]
        for i in range(len(nums)-1, -1, -1):
            for subres in res[:]:
                res.append(subres + [nums[i]])
        return res

# 从后遍历，遇到一个数就把所有子集加上该数组成新的子集
# 在循环中res[:]不更新，而res不断有新元素push进去