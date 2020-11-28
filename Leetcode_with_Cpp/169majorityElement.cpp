class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];  // 摩尔投票法 (对拼消耗)
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == res) {
                count++;
            } else {
                count--;
                if (count == 0) { res = nums[i]; count = 1; }
            }
        }
        return res;
    }
};