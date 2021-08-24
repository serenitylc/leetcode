class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int dist = INT_MAX;
        int res = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;
                int cur = target - sum;
                if (abs(cur) < dist) {
                    dist = abs(cur);
                    res = sum;
                }
                if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};