class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res("");
        for (string str : d) {
            int j = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == str[j]) ++j;
            }
            if (j == str.size() && (str.size() > res.size() || str.size() == res.size() && str < res))
                res = str;
        }
        return res;
    }
};