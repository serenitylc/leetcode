class Solution {
public:
    string solve(string str) {
        if (str.size() <= 1) return str;
        for (int i = 0, j = str.size() - 1; i <= j; i++, j--)
            swap(str[i], str[j]);
        return str;
    }
};