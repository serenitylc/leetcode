class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    res = max(res, dp[i]);
                }
            }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 二分查找 O(nlogn)
        if(nums.size() == 0)
            return 0;
        // 存放找到的上升子序列（其中元素值越小越好，这样当加入一个新值的时候，构成上升子序列的可能性就越大。）
        vector<int> dp;   
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            }else {
                int aim = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[aim] = nums[i];
            }
        }
        return dp.size();
    }
};