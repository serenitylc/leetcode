class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k > n) return res;
        vector<int> path;
        backtrace(k, n, res, path, 1);
        return res;
    }
    void backtrace(int k, int n, vector<vector<int>>& res, vector<int>& path, int index) {
        if (k < 0 || n < 0) return;
        if (k == 0 && n == 0) {
            res.push_back(path);
            return;
        }
        for (int i = index; i <= 9; ++i) {
            path.push_back(i);
            backtrace(k-1, n-i, res, path, i+1);
            path.pop_back();
        }
    }
};