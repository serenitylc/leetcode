// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
// 发现规律--斐波那契
class Solution {
public:
    int rectCover(int number) {
        if (number == 1 || number == 2) return number;
        int n1 = 1, n2 = 2, res;
        for (int i = 3; i <= number; ++i) {
            res = n1 + n2;
            n1 = n2;
            n2 = res;
        }
        return res;
    }
};