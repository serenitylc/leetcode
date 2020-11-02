class Solution {
public:
    int numTrees(int n) {
        if (n < 2) return 1;
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += numTrees(i - 1) * numTrees(n - i);
        return sum;
    }
};

class Solution {
public:
    int numTrees(int n) {
        if (n < 2) return 1;
        static unordered_map<int, int> dic;
        if (dic.find(n) != dic.end()) return dic[n];
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += numTrees(i - 1) * numTrees(n - i);
        dic[n] = sum;
        return sum;
    }
};

class Solution {
public:
    int numTrees(int n) {
        // dp[i] 表示i个节点能组成的二叉搜索树的数量
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};