class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {  // 已出现的值-->已出现的索引-->根据索引取负, 保证已出现过的值为负, 消失数索引对应值则为正
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) nums[index] *= -1;
        }
        for (int i = 0; i < n; i++)
            if (nums[i] > 0) res.push_back(i + 1);
        return res;
    }
};