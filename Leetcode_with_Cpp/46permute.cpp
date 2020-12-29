class Solution {
private:
    vector<vector<int>> res;
    vector<bool> visited;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return res;
        visited = vector<bool>(nums.size(), false);
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
    void backtrack(const vector<int>& nums, vector<int>& track) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                track.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, track);
                track.pop_back();
                visited[i] = false;
            }
        }
    }
};