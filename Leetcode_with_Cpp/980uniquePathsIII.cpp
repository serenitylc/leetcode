class Solution {
public:
    vector<int> dirs = { -1, 0, 1, 0, -1 };
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        int res = 0, cnt = 0, x, y;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    x = i, y = j;
                } else if (grid[i][j] == 0) {
                    ++cnt;
                }
            }
        }
        dfs(grid, x, y, res, cnt + 1);
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& res, int cnt) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return;
        if (grid[i][j] == 2 && cnt == 0) {
            ++res;
            return;
        }
        int val = grid[i][j];  // 记录当前值
        grid[i][j] = -1;
        int ni, nj;
        for (int d = 0; d < 4; ++d) {
            ni = i + dirs[d], nj = j + dirs[d + 1];
            dfs(grid, ni, nj, res, cnt - 1);
        }
        grid[i][j] = val;  // 回溯
    }
};