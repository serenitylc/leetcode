class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        generateSubsets(nums, res, tmp, 0);
        return res;
    }
    void generateSubsets(vector<int>& nums, vector<vector<int>>& res, vector<int> tmp, int start) {
        res.push_back(tmp);
        for(int i = start; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            generateSubsets(nums, res, tmp, i+1);
            tmp.pop_back();
        }
    }
};