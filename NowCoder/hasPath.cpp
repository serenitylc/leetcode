class Solution {
public:
    vector<int> dirt = {1, 0, -1, 0, 1};
    bool hasPath(vector<vector<char> >& matrix, string word) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
               if (dfs(matrix, i, j, 0, word, visited)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> >& matrix, int x, int y, int w_index, string & word, vector<vector<bool> >& visited) {
        if (w_index == word.size()) return true;
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || visited[x][y] || word[w_index] != matrix[x][y]) return false;
        ++w_index;
        visited[x][y] = true;
        bool isExist = false;
        for (int i = 0; i < 4; ++i) {
            isExist = isExist || dfs(matrix, x + dirt[i], y + dirt[i+1], w_index, word, visited);
        }
        visited[x][y] = false;
        return isExist;
    }
};