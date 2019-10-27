# 滑动窗口: 可以将两个边界向某一方向滑动。例如，将[i, j)向右滑动1个元素，则变为 [i+1, j+1).
# 优化滑动窗口：定义字符到索引的映射

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        st = {}
        i, ans = 0, 0
        for j in range(len(s)):
            if s[j] in st:
                i = max(st[s[j]], i)
            ans = max(ans, j - i + 1)
            st[s[j]] = j + 1           # 定义映射
        return ans;

a = Solution()
print(a.lengthOfLongestSubstring("abcabcbb"))