class Solution {
public:
    bool isPowerOfFour(int n) {
        /* 2的倍数，且二进制表示的1在奇数位 
         * 二进制: 0b
         * 八进制: 0
         * 十六进制: 0x
         */
        return n > 0 && !(n & (n - 1)) && (n & 0x55555555);
        // 2的倍数 (2,4,6,8...)，且对3取余为1 (4,16...)
        // return n > 0 && !(n & (n - 1)) && (n % 3 == 1);
    }
};