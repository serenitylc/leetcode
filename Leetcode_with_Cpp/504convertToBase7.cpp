class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res = "";
        bool isNegative = num < 0;
        if (isNegative) num = -num;
        while (num) {
            int a = num / 7, b = num % 7;
            res = to_string(b) + res;
            num = a;
        }
        return isNegative ? "-" + res : res;
    }
};