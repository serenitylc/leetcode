// 约瑟夫环
class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n <= 0 || m <= 0) return -1;
        return n == 1 ? 0 : (LastRemaining_Solution(n-1, m) + m) % n;
    }
};

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n <= 0 || m <= 0) return -1;
        list<int> li;
        for (int i = 0; i < n; ++i) {
            li.push_back(i);
        }
        int index = 0;
        while (n > 1) {
            index = (index + m - 1) % n;
            auto it = li.begin();
            advance(it, index);  // 让it向后移动index个位置
            li.erase(it);
            --n;
        }
        return li.back();
    }
};