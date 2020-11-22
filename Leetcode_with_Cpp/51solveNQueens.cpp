class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
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
            if (!isValid(board, row, col)) continue;
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

class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col, dia1, dia2;
    // 尝试在一个n皇后问题中，摆放第index行的皇后位置，row存储摆放列
    void putQueen(int n, int index, vector<int>& row) {
        if(index == n) {
            res.push_back(generateBoard(n, row));
            return;
        }
        for(int i = 0; i < n; i++)
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]) {
                row.push_back(i);
                col[i] = true;  dia1[index+i] = true;  dia2[index-i+n-1] = true;
                putQueen(n, index+1, row);
                col[i] = false;  dia1[index+i] = false;  dia2[index-i+n-1] = false;
                row.pop_back();
            }
        return;
    }
    vector<string> generateBoard(int n, vector<int>& row) {
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for(int i = 0; i < n; i++)
            board[i][row[i]] = 'Q';
        return board;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);
        vector<int> row;
        putQueen(n, 0, row);
        return res;
    }
};

int main() {
    int n = 4;
    vector<vector<string>> res = Solution().solveNQueens(n);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < n; j++)
            cout << res[i][j] << endl;
        cout << endl;
    }
    system("pause");
    return 0;
}