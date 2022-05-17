class Solution {
public:
    bool judgeSquareSum(int c) {
        int start = 0, end = sqrt(c);
        while (start <= end) {
            //sum = start * start + end * end;  Òç³ö
            if (start * start == c - end * end) return true;
            else if (start * start > c - end * end) --end;
            else ++start;
        }
        return false;
    }
};