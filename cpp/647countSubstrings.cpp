class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += extendSubstrings(s, i, i);    // 奇数长度
            count += extendSubstrings(s, i, i+1);  // 偶数长度
        }
        return count;
    }
    int extendSubstrings(string & s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            ++count;
            --l;
            ++r;
        }
        return count;
    }
};