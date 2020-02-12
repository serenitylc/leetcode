class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j=0;
        int count[3] = {0};
        for(int i=0; i<nums.size(); i++) // 计数排序
            count[nums[i]]++;
        while(j < nums.size()) {
            if(j < count[0])
                nums[j++] = 0;
            else if(j < count[1] + count[0])
                nums[j++] = 1;
            else
                nums[j++] = 2;
        }
    }
};


// 三路快排
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;           // nums[0...zero] == 0
        int two = nums.size();   // nums[two...n-1] == 2
        for(int i=0; i<two; ) {  // nums[i] == 2 时 i 不增加
            if(nums[i] == 1)
                i++;
            else if(nums[i] == 2)
                swap(nums[i], nums[--two]);
            else
                swap(nums[i++], nums[++zero]);
        }
    }
};