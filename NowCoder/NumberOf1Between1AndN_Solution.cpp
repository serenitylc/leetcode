class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 10 == 1) ++res;
            int tmp = i / 10;
            while (tmp > 0) {
                if (tmp % 10 == 1) ++res;
                tmp /= 10;
            }
        }
        return res;
    }
};