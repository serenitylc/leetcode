class Solution {
public:
    int cutRope(int number) {
        if (number == 2) return 1;
        if (number == 3) return 2;
        vector<int> records(number, -1);
        return dfs(number, records);
    }
    int dfs(int num, vector<int>& records) {
        if (num <= 4) return num;
        if (records[num-1] != -1) return records[num-1];
        int res = 0;
        for (int i = 1; i < num; ++i) {
            res = max(res, i * dfs(num-i, records));
        }
        records[num-1] = res;
        return res;
    }
};

class Solution {
public:
    int cutRope(int number) {
        if (number == 2) return 1;
        if (number == 3) return 2;
        vector<int> dp(number + 1, -1);
        for (int i = 1; i <= 4; ++i)
            dp[i] = i;
        for (int i = 5; i <= number; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        return dp[number];
    }
};