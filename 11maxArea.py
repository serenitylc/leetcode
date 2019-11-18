class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        max_area = 0
        while left < right:
            lower_height = height[left] if height[left] < height[right] else height[right]
            max_area = max(max_area, (right - left) * lower_height)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area

# 长度从n依次下降，通过比较左右挡板长度，每次保留较长者，减小搜索空间