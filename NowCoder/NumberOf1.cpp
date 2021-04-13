class Solution {
public:
     int NumberOf1(int n) {
         int res = 0;
         while (n) {
             n = n & (n-1);
             ++res;
         }
         return res;
     }
};