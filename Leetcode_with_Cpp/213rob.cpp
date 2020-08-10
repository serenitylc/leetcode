class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
    int robRange(vector<int>& nums, int start, int end) {
        // dp[i] 状态转移只与最近两个状态相关
        int dp_i_1 = 0, dp_i_2 = 0;  // dp[i+1]、dp[i+2] 
        int dp_i = 0;   // [i...nums.size()-1]
        for(int i = end; i >= start; i--) {
            dp_i = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};