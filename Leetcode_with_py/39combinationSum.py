class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if not candidates:
            return []
        if min(candidates) > target:
            return []
        candidates.sort()
        res = []
        def backtrace(candidates, target, temp_list):
            if target == 0:
                res.append(temp_list)
            if target < 0:
                return
            for i in range(len(candidates)):
                if candidates[i] > target:
                    break
                backtrace(candidates[i:], target - candidates[i], temp_list + [candidates[i]])
        backtrace(candidates, target, [])
        return res

# 回溯算法关键在于: 不合适就退回上一步
# 然后通过约束条件, 减少时间复杂度.