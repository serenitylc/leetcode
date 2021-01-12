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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count = 0;
        int digit = 0;
        /* 一圈一圈的处理, 从最外层处理到最内层 */
        while (n - 2 * count > 1) {
            /* 处理一条边 */
            for (int i = count; i < n - count - 1; ++i) {
                // 四次旋转
                digit = matrix[count][i];
                matrix[count][i] = matrix[n - i - 1][count];
                matrix[n - i - 1][count] = matrix[n - count - 1][n - i - 1];
                matrix[n - count - 1][n - i - 1] = matrix[i][n - count - 1];
                matrix[i][n - count - 1] = digit;
            }
            count++;
        }  
    }
};
