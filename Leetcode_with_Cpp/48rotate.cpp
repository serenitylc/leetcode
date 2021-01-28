class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 转置
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        // 镜像对称
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
};

class Solution {
public:
    /* 一圈一圈的处理, 从最外层处理到最内层 */
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0, n = matrix.size() - 1;
        for (int i = 0; i <= n/2; ++i) {
            for (int j = i; j < n-i; ++j) {
                temp = matrix[j][n-1];
                matrix[j][n-1] = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = temp;
            }
        }  
    }
};
