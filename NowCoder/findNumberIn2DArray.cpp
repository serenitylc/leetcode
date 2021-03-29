class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n-1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) --col;
            else ++row;
        }
        return false;
    }
};