class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, num = 0;
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] == ' ')
                continue;
            if (s[i] == '(') {
                int left = 1, right = 0, j;
                for (j = i + 1; j < s.size(); j++) {
                    if (s[j] == '(')
                        left++;
                    else if (s[j] == ')')
                        right++;
                    if (left == right)
                        break;
                }
                res += sign * calculate(s.substr(i+1, j-1-i));
                num = 0;
                i = j;
            } else if (s[i] == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (s[i] == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else {
                num = num * 10 + (s[i] - '0');
            }
        }
        res += sign * num;
        return res;
    }
};