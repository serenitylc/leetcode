class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else if (x >= 0 && x < 10) return true;
        else if (x % 10 == 0) return false;
        int tmp = x;
        unsigned int res = 0;  // 反转可能导致溢出
        while (tmp != 0) {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return (res == x);
    }
};