class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n <= 0 || k <= 0 || n < k) return res;
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }
    void backtrack(int n, int k, int pos, vector<int>& track) {
        if (track.size() == k) {
            res.push_back(track);
            return;
        }
        for (int i = pos; i <= n - (k - track.size()) + 1; ++i) {  // 剪枝--减少循环次数
            track.push_back(i);
            backtrack(n, k, i + 1, track);
            track.pop_back();
        }
    }
};