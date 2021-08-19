class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        unordered_set<char> se{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (l <= r) {
            if (se.find(s[l]) == se.end()) {
                l++;
            } else if (se.find(s[r]) == se.end()) {
                r--;
            } else {
                swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};