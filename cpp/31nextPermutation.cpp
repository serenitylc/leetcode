// 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
// 必须 原地 修改，只允许使用额外常数空间。

/* 判断按照字典序有木有下一个，如果完全降序就没有下一个
 * 如何判断有木有下一个呢？只要存在a[i-1] < a[i]的升序结构，就有，而且我们应该从右往左找，一旦找到才是真正下一个
 * 当发现a[i-1] < a[i]的结构时，从在[i, ∞]中找到最接近a[i-1]并且又大于a[i-1]的数字，由于降序，从右往左遍历即可得到k
 * 然后交换a[i-1]与a[k]，然后对[i, ∞]排序即可，排序只需要首尾不停交换即可，因为已经是降序. 比如[0,5,4,3,2,1]，下一个是[1,0,2,3,4,5]
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int j = nums.size() - 1; 
        while (j-1 >= 0 && nums[j-1] >= nums[j]) { 
            --j;
        }
        if (j == 0) {
            for (int i = 0; i < nums.size() / 2; ++i) {
                swap(nums[i], nums[nums.size() - 1 - i]);
            }
            return;
        }
        int r = nums.size() - 1;
        while (r >= j) {
            if (nums[r] > nums[j-1]) break;
            --r;
        }
        swap(nums[r], nums[j-1]);
        int cnt = (nums.size() - j) / 2;
        int i = 0;
        while (cnt > 0) {
            swap(nums[j+i], nums[nums.size() - 1 - i]);
            ++i;
            --cnt;
        }
        return;
    }
};