class Solution(object):
    def fourSum(self, nums, target):
        if len(nums) < 4:
            return []
        nums.sort()
        res = []
        for i in range(len(nums) - 3):
            if nums[i] + nums[i+1] * 3 > target:
                break 
            if i > 0 and nums[i] == nums[i-1]:
                continue  
            if nums[i] + nums[-1] * 3 < target:
                continue  
            for j in range(i+1, len(nums)-2):
                if nums[i] + nums[j] + nums[j+1] * 2 > target:
                    break
                if nums[i] + nums[j] + nums[-1] * 2 < target:
                    continue
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                low, high = j + 1, len(nums) - 1
                while low < high:
                    sum = nums[i] + nums[j] + nums[low] + nums[high]
                    if sum > target:
                        high -= 1
                    elif sum < target:
                        low += 1
                    else:
                        res.append([nums[i], nums[j], nums[low], nums[high]])
                        while low < high and nums[low] == nums[low+1]:
                            low += 1
                        while low < high and nums[high] == nums[high-1]:
                            high -= 1
                        low += 1
                        high -= 1
        return res

        