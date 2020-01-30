class Solution {
     map<char,string> mp = { {'2', "abc"},
                             {'3', "def"},
                             {'4', "ghi"},
                             {'5', "jkl"},
                             {'6', "mno"},
                             {'7', "pqrs"},
                             {'8', "tuv"},
                             {'9', "wxyz"}                 
        };
        vector<string> res;
        string cur;
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return res;
        DFS(digits);
        return res;
    }
    void DFS(string digits){  // 回溯法
        if(!digits.size())
            res.push_back(cur);
        else{
            char num = digits[0];
            string letter = mp[num];
            for(int i=0; i<letter.size(); i++)
            {
                cur.push_back(letter[i]);
                DFS(digits.substr(1));  // 取字串 依次去掉字符串首字符
                cur.pop_back();
            }
        }
    }
};