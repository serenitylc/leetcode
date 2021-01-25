class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool res = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrack(board, word, i, j, 0, visited, res);
            }
        }
        return res;
    }
    void backtrack(vector<vector<char>>& board, string & word, int i, int j, int pos, vector<vector<bool>>& visited, bool & res) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (visited[i][j] || res || board[i][j] != word[pos])
            return;
        if (pos == word.size() - 1) {
            res = true;
            return;
        }
        visited[i][j] = true;
        backtrack(board, word, i+1, j, pos+1, visited, res);
        backtrack(board, word, i-1, j, pos+1, visited, res);
        backtrack(board, word, i, j+1, pos+1, visited, res);
        backtrack(board, word, i, j-1, pos+1, visited, res);
        visited[i][j] = false;
    }
};