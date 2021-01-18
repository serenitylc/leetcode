class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0, right;
        for (int i = 0; i < n + 1; ++i) {
            if (s[i] == ' ' || s[i] == '\0') {
                for (right = i - 1; left < right; ++left, --right)
                    swap(s[left], s[right]);
                left = i + 1;
            }
        }
        return s;
    }
};