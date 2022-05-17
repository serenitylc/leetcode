class Solution {
private:
    vector<vector<char>> res;
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
        board = res;
        return;
    }
    void backtrack(vector<vector<char>>& board, int i, int j) {
        int m = 9, n = 9;
        if (i == m) { res = board; return; }
        if (j == n) { backtrack(board, i + 1, 0); return; }
        if (board[i][j] != '.') { backtrack(board, i, j + 1); return; }
        for (char ch = '1'; ch <= '9'; ch++) {
            if (!isValid(board, i, j, ch)) continue;
            board[i][j] = ch;
            backtrack(board, i, j + 1);
            board[i][j] = '.';
        }
    }
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;
            if (board[i][c] == ch) return false;
            // 判断 3 x 3 方框是否存在重复
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch) return false;
        }
        return true;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        int m = 9, n = 9;
        if (i == m) return true;
        if (j == n) return backtrack(board, i + 1, 0);
        if (board[i][j] != '.') return backtrack(board, i, j + 1);
        for (char ch = '1'; ch <= '9'; ch++) {
            if (!isValid(board, i, j, ch)) continue;
            board[i][j] = ch;
            if (backtrack(board, i, j + 1)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;
            if (board[i][c] == ch) return false;
            // 判断 3 x 3 方框是否存在重复
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch) return false;
        }
        return true;
    }
};