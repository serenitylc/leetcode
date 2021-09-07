class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i * 2 <= n; ++i) {
            if (n % i == 0) {
                bool isMatch = true;
                for (int j = i; j < n; ++j) {
                    if (s[j] != s[j - i]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) return true;
            }
        }
        return false;
    }
};
