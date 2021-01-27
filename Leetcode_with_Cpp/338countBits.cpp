class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i = 1; i <= num; ++i) {
            /* i >> 1会把最低位去掉，因此i >> 1 也是比i小的，在前面的数组里算过。
             * 当 i 的最低位是0，则 i 中1的个数和i >> 1中1的个数相同；当i的最低位是1，i 中1的个数是 i >> 1中1的个数再加1
             */
            dp[i] = i & 1 ? dp[i-1] + 1 : dp[i>>1];
            /* i & (i - 1)可以去掉i最右边的一个1（如果有），因此 i & (i - 1）是比 i 小的
             * 且i & (i - 1)的1的个数已经在前面算过了，所以i的1的个数就是 i & (i - 1)的1的个数加上1
             */
            // dp[i] = dp[i & (i-1)] + 1;
        }
        return dp;
    }
};