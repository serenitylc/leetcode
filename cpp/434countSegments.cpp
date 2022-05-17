class Solution {
public:
    int countSegments(string s) {
        s += ' ';
        int res = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] != ' ' && s[i+1] == ' ')
                res++;
        return res;
    }
};