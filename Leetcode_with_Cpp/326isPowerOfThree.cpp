class Solution {
public:
    bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    double a = log10(n) / log10(3) ;  // 换底
    return  a == floor(a);           // 判断换底后的log3n是否为整数，即n是否为3的倍数
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)  return false;
        while (n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        int a = 1;                  // a不断乘3，看是否与n相等
        while (n >= a) {
            if (a == n) return true; 
            if (a >= INT_MAX / 3) return false;
            a *= 3;
        }
        return false;
    }
};