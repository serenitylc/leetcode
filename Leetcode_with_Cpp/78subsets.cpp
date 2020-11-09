class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {{}};
        int n = nums.back();
        nums.pop_back();
        vector<vector<int>> res = subsets(nums);
        int sz = res.size();
        for (int i = 0; i < sz; i++) {
            res.push_back(res[i]);
            res.back().push_back(n);
        }
        return res;
    }
};

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i + 1, track);
            track.pop_back();
        }
    }
};