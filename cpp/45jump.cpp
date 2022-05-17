class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int fastest = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            fastest = max(fastest, i + nums[i]);
            if (end == i) {
                res++;
                end = fastest;
            }
        }
        return res;
    }
};

class Solution {
public:
    int dp(vector<int>& nums, int p, vector<int>& memo) {
        int n = nums.size();
        if (p >= n-1) return 0;
        if (memo[p] != n) return memo[p];
        int step = nums[p];
        for (int i = 1; i <= step; ++i) {
            memo[p] = min(memo[p], 1 + dp(nums, p+i, memo));
        }
        return memo[p];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, n);
        return dp(nums, 0, memo);
    }
};