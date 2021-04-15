// 反转数字(考虑溢出,必须在溢出前进行判断)
class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 0) isNeg = true;
        if (isNeg) x = -x;
        int res = 0;
        while (x) {
            int tmp = x % 10;
            if (res > (MAX_INT - tmp) / 10)) return -1;
            res  = res * 10 + tmp;
            x /= 10;
        }
        return isNeg ? -res : res;
    }
};