class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return n;
        vector<int> nums(n, 1);
        for (int i = 1; i < n; ++i)  // 贪心策略 每次遍历只考虑并更新相邻一侧的大小关系
            if (ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
        for (int i = n - 1; i > 0; --i)
            if (ratings[i - 1] > ratings[i]) nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        return accumulate(nums.begin(), nums.end(), 0);
    }
};