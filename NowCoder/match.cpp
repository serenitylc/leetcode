class Solution {
public:
    bool match(string str, string pattern) {
        return match(str, pattern, 0, 0);
    }
    bool match(string& str, string& pattern, int i, int j) {
        /* Four case:
         * i,j皆完成遍历 -- true
         * i,j皆未完成遍历 -- 先判断pattern[j+1]是否为*,再判断str[i]和pattern[j]是否相等; 若是,分别匹配 若干次/1次/0次
         * i完成遍历, j未完成遍历 -- pattern可能以*结尾
         * i未完成遍历,j完成遍历 -- false */
        if (i == str.size() && j == pattern.size()) return true;
        if (i != str.size() && j == pattern.size()) return false;
        if (pattern[j+1] == '*') {
            if (str[i] == pattern[j] || (i != str.size() && pattern[j] == '.'))
                return match(str, pattern, i+1, j) || match(str, pattern, i+1, j+2) || match(str, pattern, i, j+2);
            else return match(str, pattern, i, j+2);
        } else {
            if (str[i] == pattern[j] || (i != str.size() && pattern[j] == '.'))
                return match(str, pattern, i+1, j+1);
            else return false;
        }
    }
};