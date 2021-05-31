class Solution {
public:
    string solve(string s, string t) {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        string res;
        int k = 0;
        for (int i = 0; i < s.size() || i < t.size(); ++i) {
            if (i < s.size()) k += s[i] - '0';
            if (i < t.size()) k += t[i] - '0';
            res += k % 10 + '0';
            k /= 10;
        }
        if (k) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};