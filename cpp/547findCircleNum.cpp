class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(M, i, visited);
                ++count;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& M, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int k = 0; k < M.size(); ++k) {
            if (M[i][k] == 1 && !visited[k])
                dfs(M, k, visited);
        }
    }
};