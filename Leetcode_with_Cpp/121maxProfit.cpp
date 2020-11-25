class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_0 = 0, dp_i_1 = INT_MIN;   // base (i = -1)
        for (int i = 0; i < n; i++) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};

/* k = 1:
 * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
 * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 
 *             = max(dp[i-1][1][1], -prices[i])
 * 解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。
 * 
 * 现在发现 k 都是 1，不会改变，即 k 对状态转移已经没有影响了。
 * 进一步化简去掉所有 k：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], -prices[i])
 */