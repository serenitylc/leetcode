class Solution(object):
    def combine(self, n, k):
        def generateCombine(start, temp):
            if len(temp) == k:
                res.append(temp)
                return
            for i in range(start, n-(k-len(temp))+2):
                generateCombine(i+1, temp+[i])
            return
        if n<=0 or k<=0 or n<k:
            return []
        res = []
        generateCombine(1, [])
        return res

class Solution(object):
    def combine(self, n, k):
        if n<=0 or k<=0 or n<k:
            return []
        # ÅÅÁĞ×éºÏ£º C(m,n) = C(m-1,n) + C(m-1,n-1)
        if k==1:
            return [[i] for i in range(1, n+1)]
        if k==n:
            return [[i for i in range(1, n+1)]]
        res = self.combine(n-1, k)
        for item in self.combine(n-1, k-1):
            item.append(n)
            res.append(item)
        return res