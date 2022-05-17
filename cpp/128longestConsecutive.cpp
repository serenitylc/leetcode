class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> se(nums.begin(), nums.end());
        for (auto it = se.begin(); it != se.end(); it++) {
            int tmp = *it;
            if (se.count(tmp - 1) == 1) continue;
            int count = 1;
            while (se.count(tmp + count)) {
                count++;
            }
            res = max(res, count);
        }
        return res;
    }
};