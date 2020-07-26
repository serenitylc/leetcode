class Solution {
private:
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool>> visited;
    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
    // ´Ó board[x][y] ¿ªÊ¼£¬Ñ°ÕÒ word[index...word.size()]
    bool searchWord(const vector<vector<char>>& board, const string& word, int index, int x, int y) {
        if(index == word.size() - 1)
            return board[x][y] == word[index];
        if(board[x][y] == word[index]) {
            visited[x][y] = true;
            for(int i = 0; i < 4; i++) {
                int newX = x + d[i][0];
                int newY = y + d[i][1];
                if(isArea(newX, newY) && !visited[newX][newY] && searchWord(board, word, index+1, newX, newY))
                    return true;
            }
            visited[x][y] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        assert(m > 0);
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(searchWord(board, word, 0, i, j))
                    return true;
        return false;
    }
};