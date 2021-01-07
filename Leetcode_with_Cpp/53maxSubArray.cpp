class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int res= nums[0];
        vector<int> dp(nums.size(), res);
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};