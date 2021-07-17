class Solution {
public:
    // 数组中有重复数字就可以认为数组转换为链表后有环
    // 将数组看成是链表：第i个位置指向第nums[i]的位置的结点
    // 分为两个步骤
    // 1、先寻找链表中环的入口（将快指针入环）
    // 2、将慢指针重回原点，搜索整个链表
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[slow];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};