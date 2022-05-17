class Solution {
public:
    vector<int> dire{-1, 0, 1, -1, -1, 1, 1, 0, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty() || grid[0][0] != 0) return -1;
        int res = 0;
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            res++;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [r, c] = q.front();
                q.pop();
                if (r == n-1 && c == n-1) {
                    return res;
                }
                for (int j = 0; j < 8; ++j) {
                    int x = r + dire[j];
                    int y = c + dire[j+1];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]) {
                        q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};