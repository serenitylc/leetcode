class Solution {
public:
    const long MAX = (1<<31)-1, MIN = (-1<<31);  // 最大最小值
    int reverse(int x) {
        if(x/10 == 0) return x;  // 绝对值小于10，直接返回
        long y = 0;
        while(x) {
            y *= 10;
            if(y > MAX || y < MIN) 
                return 0;
            y += x % 10;  // 取出x的个位
            x /= 10;      // 去掉x的个位
        }
        return y;
    }
};