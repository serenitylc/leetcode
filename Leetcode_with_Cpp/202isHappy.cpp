class Solution {
private:
    unordered_set<int> history;
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        if (history.find(n) != history.end()) return false;
        history.insert(n);
        int tmp = 0;
        while (n) { tmp += (n % 10) * (n % 10); n /= 10; }
        return isHappy(tmp);
    }
};

class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while(slow != fast);
        return slow == 1;
    }
};

// 若给定数字最后会一直循环重复，那么快指针（值）一定会追上慢指针（值），也就是两者一定会相等
// 若没有循环重复，最后快慢指针也会相等，且都等于1。