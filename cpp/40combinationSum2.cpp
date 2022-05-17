class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        backtrace(candidates, track, 0, target);
        return res;
    }
    void backtrace(vector<int>& candidates, vector<int>& track, int pos, int target) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
                if (i != pos && candidates[i] == candidates[i-1])  // 去掉重复
                    continue;
                track.push_back(candidates[i]);
                backtrace(candidates, track, i + 1, target-candidates[i]);
                track.pop_back();
            } else {  // 剪枝
                break;
            }
        }
    }
};