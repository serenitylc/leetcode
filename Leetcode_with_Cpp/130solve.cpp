class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> keep(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(board, keep, i, 0);
            dfs(board, keep, i, n-1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(board, keep, 0, j);
            dfs(board, keep, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !keep[i][j])
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& keep, int i, int j) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O' && !keep[i][j]) {
            keep[i][j] = true;
            dfs(board, keep, i+1, j);
            dfs(board, keep, i-1, j);
            dfs(board, keep, i, j+1);
            dfs(board, keep, i, j-1);
        }
    }
};