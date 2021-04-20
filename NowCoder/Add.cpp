class Solution {
public:
    int Add(int num1, int num2) {
        int res, i;
        do {
            res = num1 ^ num2;  // 每一位相加
            i = (num1 & num2) << 1;  // 进位
            num1 = res;
            num2 = i;
        } while(i != 0);
        return res;
    }
};