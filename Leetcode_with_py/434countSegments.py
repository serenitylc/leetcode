class Solution(object):
    def countSegments(self, s):
        s += ' '
        res = 0
        for i in range(len(s)):
            if s[i] != ' ' and s[i+1] == ' ':
                res += 1
        return res