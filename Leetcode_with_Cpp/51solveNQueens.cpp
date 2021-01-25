class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col))
                continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列
        for (int i = 0; i < n; i++)
            if (board[i][col] == 'Q') return false;
        // 检查右上方
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        // 检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        return true;
    }
};

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

int main() {
    int n = 4;
    vector<vector<string>> res = Solution().solveNQueens(n);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << endl;
        cout << endl;
    }
    system("pause");
    return 0;
}