class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        nums_freq_dict = {}
        res = [[] for i in range(len(nums)+1)]
        for i in nums:
            if i in nums_freq_dict:
                nums_freq_dict[i] += 1
            else:
                nums_freq_dict[i] = 1
                
        for num, freq in nums_freq_dict.items():
            res[freq].append(num)
        
        ans = []
        for i in range(len(nums), 0, -1):
            if len(res[i]) == 0:
                continue
            ans.extend(res[i])
            if len(ans) == k:
                return ans