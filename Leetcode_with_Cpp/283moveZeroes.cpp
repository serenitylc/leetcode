class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        while (j<nums.size())
            nums[j++] = 0;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i != j)
                    swap(nums[j++], nums[i]);
                else
                    j++;
            }
        }
    }
};