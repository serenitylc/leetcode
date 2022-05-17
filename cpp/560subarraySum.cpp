class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        int res = 0;
        for (int i = 0; i < sums.size(); ++i) {
            for (int j = i + 1; j < sums.size(); ++j) {
                res += sums[j] - sums[i] == k;
            }
        }
        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> cul;
        cul[0] = 1;
        for (auto & m : nums) {
            sum += m;
            res += cul[sum - k];
            ++cul[sum];
        }
        return res;
    }
};