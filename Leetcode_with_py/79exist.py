class Solution(object):
    directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]

    def exist(self, board, word):
        m = len(board)
        if m == 0:
            return False
        n = len(board[0])
        marked = [[False for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if self.searchWord(board, word, 0, i, j, marked, m, n):
                    return True
        return False

    def searchWord(self, board, word, index, x, y, marked, m, n):
        if index == len(word) - 1:
            return board[x][y] == word[index]
        if board[x][y] == word[index]:
            marked[x][y] = True
            for direction in self.directions:
                newX = x + direction[0]
                newY = y + direction[1]
                if 0 <= newX < m and 0 <= newY < n and not marked[newX][newY] and \
                        self.searchWord(board, word, index + 1, newX, newY, marked, m, n):
                    return True
            marked[x][y] = False
        return False