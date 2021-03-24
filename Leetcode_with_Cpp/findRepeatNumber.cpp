class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); ++i) {
            if (ump.find(nums[i]) != ump.end()) return nums[i];
            else ump[nums[i]]++;
        }
        return -1;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]]) return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};