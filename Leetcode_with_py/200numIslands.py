class Solution(object):
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    def dfs(self, grid, visited, m, n, x, y):
        visited[x][y] = True
        for direction in self.directions:
            newX = x + direction[0]
            newY = y + direction[1]
            if 0 <= newX < m and 0 <= newY < n and not visited[newX][newY] and \
                    grid[newX][newY] == '1':
                self.dfs(grid, visited, m, n, newX, newY)

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    res += 1
                    self.dfs(grid, visited, m, n, i, j)
        return res