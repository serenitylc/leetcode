class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_k1_0 = 0, dp_i_k1_1 = INT_MIN;  // k = 1
        int dp_i_k2_0 = 0, dp_i_k2_1 = INT_MIN;  // k = 2
        for (int i = 0; i < n; i++) {
            dp_i_k2_0 = max(dp_i_k2_0, dp_i_k2_1 + prices[i]);
            dp_i_k2_1 = max(dp_i_k2_1, dp_i_k1_0 - prices[i]);  // k = 2 依赖于 k = 1 进行更新
            dp_i_k1_0 = max(dp_i_k1_0, dp_i_k1_1 + prices[i]);
            dp_i_k1_1 = max(dp_i_k1_1, -prices[i]);  // k = 1 依赖于 k = 0 进行更新 (dp_i_k0 == 0)
        }
        return dp_i_k2_0;  // 在第i天，至少进行2次交易，最终不持有股票，所得最大利益。
    }
};
/* k = 2:
 * 原始的动态转移方程，没有可化简的地方
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 *
 * 由于没有消掉 k 的影响，所以必须要对 k 进行穷举：
 * int max_k = 2;
 * int[][][] dp = new int[n][max_k + 1][2];
 * for (int i = 0; i < n; i++) {
 *    for (int k = max_k; k >= 1; k--) {
 *        if (i - 1 == -1) { // 处理 base case }
 *        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
 *        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
 *    }
 * }
 * // 穷举了 n × max_k × 2 个状态，正确。
 * return dp[n - 1][max_k][0];
 *
 * 直接把 k = 1 和 2 的情况全部列举出来也可以.
 */