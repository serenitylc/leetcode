class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(matrix, i, 0, can_reach_p);
            dfs(matrix, i, n-1, can_reach_a);
        }
        for (int j = 0; j < n; ++j) {
            dfs(matrix, 0, j, can_reach_p);
            dfs(matrix, m-1, j, can_reach_a);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (can_reach_p[i][j] && can_reach_a[i][j])
                    res.push_back(vector<int>{i, j});
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<bool>>& can_reach) {
        //if (can_reach[r][c]) return;
        can_reach[r][c] = true;
        int x, y;
        for (int i = 0; i < 4; ++i) {
            x = r + directions[i];
            y = c + directions[i+1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && !can_reach[x][y] && matrix[x][y] >= matrix[r][c])
            dfs(matrix, x, y, can_reach);
        }
    }
};