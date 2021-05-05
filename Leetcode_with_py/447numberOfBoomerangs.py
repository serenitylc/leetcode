class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in points:
            dic = {}
            for j in points:
                distance = (i[0] - j[0])**2 + (i[1] - j[1])**2
                if distance not in dic:
                    dic[distance] = 1
                else:
                    dic[distance] += 1
            for val in dic.values():
                if val >= 2:
                    res += val*(val-1)
        return res