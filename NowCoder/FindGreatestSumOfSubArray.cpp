class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res = INT_MIN;
        vector<int> dp;
        dp.reserve(array.size());
        dp[0] = array[0];
        for (int i = 1; i < array.size(); ++i) {
            dp[i] = max(dp[i-1] + array[i], array[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};