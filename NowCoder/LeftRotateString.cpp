class Solution {
public:
    string LeftRotateString(string str, int n) {
        int sz = str.size();
        if (sz == 0) return "";
        if (n > sz) n %= sz;
        for (int i = 0; i < n/2; ++i) {
            swap(str[i], str[n-i-1]);
        }
        for (int j = n; j < (sz-n)/2+n; ++j) {
            swap(str[j], str[sz-j+n-1]);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int sz = str.size();
        if(sz == 0) return "";
        n = n % sz;
        str += str;
        return str.substr(n, sz);
    }
};

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (n > str.size()) return str;
        return str.substr(n) + str.substr(0, n);
    }
};