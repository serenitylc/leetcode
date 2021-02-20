class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right])  // 没旋转
                return nums[left];
            int mid = left + right >> 1;
            if (nums[mid] == nums[left]) {  // 无法判断左边都一样还是右边都一样
                ++left;
            } else if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};