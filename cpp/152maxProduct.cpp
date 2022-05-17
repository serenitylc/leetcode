class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int maxV = 1, minV = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) swap(maxV, minV);
            maxV = max(maxV * nums[i], nums[i]);
            minV = min(minV * nums[i], nums[i]);
            res = max(maxV, res);
        }
        return res;
    }
};