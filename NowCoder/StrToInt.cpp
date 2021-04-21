class Solution {
public:
    int StrToInt(string str) {
        if (str.empty()) return 0;
        bool isNeg = false;
        int index = 0;
        int res = 0;
        if (str[index] == '-') {
            isNeg = true;
            ++index;
        } else if (str[index] == '+') {
            ++index;
        }
        for (int i = index; i < str.size(); ++i) {
            if (!isdigit(str[i])) return 0;
            int num = str[i] - '0';
            if ((!isNeg && 10 * res > INT_MAX - num) || (isNeg && 10 * res > INT_MAX - num + 1)) return 0;
            res = res * 10 + num;
        }
        return isNeg ? -res : res;
    }
};