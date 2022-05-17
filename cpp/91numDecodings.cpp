class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int pre = s[0] - '0';
        if (pre == 0) return 0;
        if (n == 1) return 1;
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; ++i) {
            int cur = s[i-1] - '0';
            if ((pre == 0 || pre > 2) && cur == 0)
                return 0;
            if (pre == 1 || (pre == 2 && cur < 7)) {
                if (cur == 0) {
                    dp[i] = dp[i-2];
                } else {
                    dp[i] = dp[i-1] + dp[i-2];
                }
            } else {
                dp[i] = dp[i-1];
            }
            pre = cur;
        }
        return dp[n];
    }
};