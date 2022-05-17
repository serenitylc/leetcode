class Solution {
private:
    map<char,string> mp = { {'2', "abc"},
                            {'3', "def"},
                            {'4', "ghi"},
                            {'5', "jkl"},
                            {'6', "mno"},
                            {'7', "pqrs"},
                            {'8', "tuv"},
                            {'9', "wxyz"} };
    vector<string> res;
    string cur;
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return res;
        dfs(digits);
        return res;
    }
    void dfs(string digits) {
        if (!digits.size()) {
            res.push_back(cur);
        } else {
            char num = digits[0];
            string letter = mp[num];
            for (int i = 0; i < letter.size(); i++) {
                cur.push_back(letter[i]);
                dfs(digits.substr(1));   // 依次去掉字符串首字符
                cur.pop_back();
            }
        }
    }
};
// s.substr(pos, n)：pos 默认值 0，n 默认值 s.size() - pos