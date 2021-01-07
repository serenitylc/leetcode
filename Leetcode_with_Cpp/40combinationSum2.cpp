class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> p;
        backtrace(candidates, p, 0, target);
        return res;
    }
    void backtrace(vector<int>& candidates, vector<int>& p, int pos, int target) {
        if (target == 0) {
            res.push_back(p);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                if (i != pos && candidates[i] == candidates[i-1]) // »•µÙ÷ÿ∏¥
                    continue;
                p.push_back(candidates[i]);
                backtrace(candidates, p, i + 1, target-candidates[i]);
                p.pop_back();
            } else { // ºÙ÷¶
                break;
            }
        }
    }
};