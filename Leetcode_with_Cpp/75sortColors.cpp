class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 计数排序
        int count[3] = {0};
        for (int i = 0; i < nums.size(); ++i)
            count[nums[i]]++;
        int j = 0;
        while (j < nums.size()) {
            if (j < count[0])
                nums[j++] = 0;
            else if (j < count[1] + count[0])
                nums[j++] = 1;
            else
                nums[j++] = 2;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 三路快排
        int zero = -1;           // nums[0...zero] == 0
        int two = nums.size();   // nums[two...n-1] == 2
        for (int i = 0; i < two; ) {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 2)  // nums[i] == 2 时 i 不增加
                swap(nums[i], nums[--two]);
            else
                swap(nums[i++], nums[++zero]);
        }
    }
};