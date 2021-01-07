class Solution {
private:
    vector<vector<int>> res;
    void backtrace(vector<int>& candidates, int target, vector<int>& p, int index) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(p);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            p.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], p, i);
            p.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;
        vector<int> p;
        backtrace(candidates, target, p, 0);
        return res;
    }
};