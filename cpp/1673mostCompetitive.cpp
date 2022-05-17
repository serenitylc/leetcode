class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        stack<int> stk;
        int n = nums.size() - 1;
        if (n + 1 < k || k < 1) return {};
        for (int i = 0; i <= n; ++i) {
            while (!stk.empty() && stk.top() > nums[i] && n - i >= k) {
                stk.pop();
                k++;
            }
            if (k <= 0) continue;
            stk.push(nums[i]);
            k--;
        }
        while (!stk.empty()) {
            res.insert(res.begin(), stk.top());
            stk.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (res.size() && res.back() > nums[i] && res.size() + len - i > k) {
                res.pop_back();
            }
            if (res.size() < k) res.push_back(nums[i]);
        }
        return res;
    }
};