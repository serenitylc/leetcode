class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(res, track, visited, nums);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& track, vector<bool>& visited, vector<int>& nums) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        int last = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            // 保证下一次回溯的根与上一次不同
            if (!visited[i] && nums[i] != last) {
                last = nums[i];
                track.push_back(nums[i]);
                visited[i] = true;
                dfs(res, track, visited, nums);
                track.pop_back();
                visited[i] = false;
            }
        }
    }
};