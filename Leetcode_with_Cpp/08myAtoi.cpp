class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int state = 0;  //  0-初始状态  1-正数  2-负数
        for (char c : s) {
            if (state == 0 && c == ' ') continue;
            else if (state == 0 && c == '+') state = 1;
            else if (state == 0 && c == '-') state = 2;
            else if (c >= '0' && c <= '9') {
                if (state == 0) state = 1;
                int tmp = c - '0';
                res = res * 10 + tmp;
                if (res > INT_MAX) break;
            } else break;
        }
        if (state == 1 && res > INT_MAX) res = INT_MAX;
        else if (state == 2) {
            res = -res;
            if (res < INT_MIN) res = INT_MIN;
        }
        return res;
    }
};