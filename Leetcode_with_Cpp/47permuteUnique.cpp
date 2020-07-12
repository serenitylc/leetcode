class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> re;
        vector<int> used(nums.size(), 0);   

        sort(nums.begin(), nums.end());
        dfs(res, re, used, nums);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& re, vector<int>& used, vector<int>& nums)
    {
        if(re.size() == nums.size()) {
            res.push_back(re);
            return;
        }
        int r = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(used[i] == 0) {
                // 针对重复数字漂亮的剪枝，前提是需要排序
                if(nums[i] != r) {
                    r = nums[i];
                    re.push_back(nums[i]);
                    used[i] = 1;

                    dfs(res, re, used, nums);

                    re.pop_back();
                    used[i] = 0;
                }
            }
        }
    }
};