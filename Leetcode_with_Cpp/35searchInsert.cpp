class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[nums.size()-1] < target)
            return nums.size();
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] >= target)
                return i;
        return 0;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0])
            return 0;
        if (target > nums.back())
            return nums.size();
        return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }
};
// lower_bound( )和upper_bound( )都是利用二分查找的方法在一个排好序的数组中进行查找的。
// lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。
// 通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。