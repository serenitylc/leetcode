class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        if (p.size() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char* s, const char* p) {
        if (*p == 0) return *s == 0;
        
        bool firstMatch = *s && (*s == *p || *p == '.');
        
        if (*(p+1) == '*') return isMatch(s, p+2) || (firstMatch && isMatch(++s, p));
        else return firstMatch && isMatch(++s, ++p);
    }
};