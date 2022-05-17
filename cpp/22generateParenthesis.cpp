class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }
    void dfs(vector<string> &res, string str, int l, int r, int n) {
        if (l > n || r > n || r > l) return;
        if (l == n && r == n) {
            res.push_back(str);
            return;
        }
        dfs(res, str + '(', l+1, r, n);
        dfs(res, str + ')', l, r+1, n);
        return;
    }
};