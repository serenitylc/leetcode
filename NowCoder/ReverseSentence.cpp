class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        int start = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') continue;
            if (i > 0 && str[i-1] == ' ') start = i;
            if (i < str.size()-1 && str[i+1] != ' ') continue;
            ReverseString(str, start, i);
        }
        reverse(str.begin(), str.end());
        return str;
    }
    void ReverseString(string & str, int start, int end) {
        if (start >= end) return;
        while (start < end) {
            char tmp = str[start];
            str[start++] = str[end];
            str[end--] = tmp;
        }
    }
};