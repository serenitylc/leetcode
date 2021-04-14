class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0) return 0;
        int exp = exponent >= 0 ? exponent : -exponent;
        double res = 1.0;
        while (exp--) {
            res *= base;
        }
        return exponent >= 0 ? res : 1/res;
    }
};