class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        if (n <= 0) return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = max(helper(A, i, i + 1), helper(A, i, i) - 1);
            res = max(res, tmp);
        }
        return res;
    }
    int helper(string & str, int l, int r) {
        int num = 0;
        while (l >= 0 && r <= str.size() - 1 && str[l--] == str[r++]) {
            num += 2;
        }
        return num;
    }
};