class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0 ; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                }
            }
        }
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] != 0) {
                    if (i < m-1) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    if (j < n-1) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                }
            }
        }
        return dp;
    }
};

class Solution {
private:
    vector<int> directions{-1, 0, 1, 0, -1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    q.push(pair<int, int>(i, j));
            }
        }
        int step = 0;
        while (!q.empty()) {
            step++;
            int sz = q.size();
            while (sz-- > 0) {
                auto [r, c] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = r + directions[k];
                    int y = c + directions[k+1];
                    if (x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] == 1) {
                        matrix[x][y] = 0;
                        res[x][y] = step;
                        q.push({x, y});
                    }
                }
            }
        }
        return res;
    }
};