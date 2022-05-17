class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int fastest = 0;
        for (int i = 0; i < n-1; ++i) {
            fastest = max(fastest, i + nums[i]);
            if (fastest <= i) return false;
        }
        return fastest >= n-1;
    }
};