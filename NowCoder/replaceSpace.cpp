class Solution {
public:
    string replaceSpace(string s) {
        // write code here
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                res += "%20";
            } else {
                res += s[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    string replaceSpace(string s) {
        // write code here
        int len = s.size();
        int count = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') ++count;
        }
        s.resize(len + count * 2);
        int i = len - 1;
        int j = s.size() - 1;
        while (i != j) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 3;
            } else {
                s[j] = s[i];
                --j;
            }
            --i;
        }
        return s;
    }
};