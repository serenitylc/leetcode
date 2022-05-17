class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.res = []
        self.func('', 0, 0, n)
        return self.res

    def func(self, str, l, r, n):
        if l == n and r == n:
            self.res.append(str)
        if l < n:
            self.func(str+'(', l+1, r, n)
        if r < l:
            self.func(str+')', l, r+1, n)