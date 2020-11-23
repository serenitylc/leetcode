class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        for (int i = 0; i <= N; i++) dp[i][1] = i;
        for (int j = 1; j <= K; j++) dp[1][j] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 2; j <= K; j++) {
                int res = INT_MAX;
                /*
                for (int floor = 1; floor <= i; floor++)
                    res = min(res, 1 + max(dp[floor - 1][j - 1], dp[i - floor][j]));
                dp[i][j] = res;
                */
                int start = 1, end = i, mid;
                while (start <= end) {
                    mid = start + (end - start) / 2;
                    if (dp[mid - 1][j - 1] == dp [i - mid][j]) {
                        res = min(res, 1 + dp[mid - 1][j - 1]);
                        break;
                    } else if (dp[mid - 1][j - 1] > dp[i - mid][j]) {
                        end = mid - 1;
                        res = min(res, 1 + dp[mid - 1][j - 1]);
                    } else {
                        start = mid + 1;
                        res = min(res, 1 + dp[i - mid][j]);
                    }
                }
                dp[i][j] = res;
            }
        }
        return dp[N][K];
    }
};