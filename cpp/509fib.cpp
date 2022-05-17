class Solution {
    vector<int> memo;
public:
    int fib(int N) {
        if (N == 0) return 0;
        memo = vector<int>(N + 1, 0);
        return helper(N);
    }
    int helper(int n) {
        if (n == 1 || n == 2) return 1;
        if (memo[n] != 0) return memo[n];
        memo[n] = helper(n - 1) + helper(n - 2);
        return memo[n];
    }
};

class Solution {
public:
    int fib(int N) {
        vector<int> dp(31, 0);
        dp[1] = 1;
        for (int i = 2; i <= N; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[N];
    }
};

class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1 || N == 2) return 1;
        int prev = 1, curr = 1;
        for (int i = 3; i <= N; i++) {
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }
};