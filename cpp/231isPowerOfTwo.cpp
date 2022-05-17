class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) {
            n >>= 1;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; 
        if ((n & n-1) == 0) return true; 
        return false;
    }
};