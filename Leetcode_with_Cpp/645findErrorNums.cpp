class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> tmp(nums.size() + 1, 0), res(2, 0);
        for (int num : nums) tmp[num]++;
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] == 2) res[0] = i;
            if (tmp[i] == 0) res[1] = i;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;  // 根据值寻找对应索引，重复值会导致两次访问索引
            if (nums[index] < 0) dup = abs(nums[i]);
            else nums[index] *= -1;
        }
        int missing = -1;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0) missing = i + 1;
        return {dup, missing};
    }
};