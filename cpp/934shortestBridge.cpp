class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> points;
        // dfs 寻找第一个岛屿，并将 1 赋值为 2
        bool flag = false;
        for (int i = 0; i < m; ++i) {
            if (flag) break;
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    dfs(A, points, m, n, i, j);
                    flag = true;
                    break;
                }
            }
        }
        // bfs 寻找第二个岛屿，并将经过的 0 赋值为 2
        int x, y;
        int res = 0;
        while (!points.empty()) {
            ++res;
            int n_points = points.size();
            while (n_points--) {
                auto [r, c] = points.front();
                points.pop();
                for (int k = 0; k < 4; ++k) {
                    x = r + directions[k];
                    y = c + directions[k+1];
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        if (A[x][y] == 1) return res;
                        if (A[x][y] == 2) continue;
                        points.push({x, y});
                        A[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }
    void dfs(vector<vector<int>>& A, queue<pair<int, int>>& points, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i == m || j == n || A[i][j] == 2)
            return;
        if (A[i][j] == 0) {
            points.push({i, j});
            return;
        }
        A[i][j] = 2;
        dfs(A, points, m, n, i-1, j);
        dfs(A, points, m, n, i+1, j);
        dfs(A, points, m, n, i, j-1);
        dfs(A, points, m, n, i, j+1);
    }
};