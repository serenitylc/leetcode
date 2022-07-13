class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        # queens:摆放皇后的位置
        # xy_dif:从左上到右下对角线x、y值相减（相等）
        # xy_sum:从右上到坐下对角线x、y值相加（相等）
        def dfs(queens, xy_dif, xy_sum):
            row = len(queens)
            if row == n:
                result.append(queens)
                return
            for col in range(n):
                if col not in queens and row-col not in xy_dif and row+col not in xy_sum:
                    dfs(queens+[col], xy_dif+[row-col], xy_sum+[row+col])
        
        result = []
        dfs([], [], [])
        return [["." * i + "Q" + "." * (n-i-1) for i in sol] for sol in result]