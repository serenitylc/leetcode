class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int row = matrix.size(), col = matrix[0].size();
        int circle = ((row < col ? row : col) + 1) / 2;
        for (int i = 0; i < circle; ++i) {
            for (int k = i; k < col - i; ++k) {
                res.push_back(matrix[i][k]);
            }
            for (int j = i + 1; j < row - i; ++j) {
                res.push_back(matrix[j][col - i - 1]);
            }
            for (int l = col - i - 2; l >= i && (row - i - 1 != i); --l) {
                res.push_back(matrix[row - i - 1][l]);
            }
            for (int m = row - i - 2; m >= i+1 && (col - i - 1 != i); --m) {
                res.push_back(matrix[m][i]);
            }
        }
        return res;
    }
};