class Solution {
public:
	int movingCount(int threshold, int rows, int cols) {
		int res = 0;
		bool* flag = new bool[rows * cols];
		memset(flag, 0, rows * cols);
		dfs(threshold, rows, cols, flag, 0, 0, res);
		return res;
	}
	void dfs(int & threshold, int & rows, int & cols, bool* & flag, int i, int j, int & res) {
		if (i < 0 || i >= rows || j < 0 || j >= cols)
			return;
		if (*(flag + i * cols + j) == 1)
			return;
		if (check(i, j, threshold)) {
			res++;
			*(flag + i * cols + j) = 1;
			dfs(threshold, rows, cols, flag, i, j - 1, res);  //вС
			dfs(threshold, rows, cols, flag, i, j + 1, res);  //ср
			dfs(threshold, rows, cols, flag, i - 1, j, res);  //ио
			dfs(threshold, rows, cols, flag, i + 1, j, res);  //об
		}
	}
    bool check(int ii, int jj, int & threshold) {
        int sum = 0;
        while (ii != 0) {
			sum += ii % 10;
			ii = ii / 10;
		}
		while (jj != 0) {
			sum += jj % 10;
			jj = jj / 10;
		}
        return sum <= threshold;
    }
};