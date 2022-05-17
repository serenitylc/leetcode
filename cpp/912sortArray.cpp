class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        HeapSort(nums, n);
        return nums;
    }
    // 堆排序
    void HeapSort(vector<int>& nums, int size) {
       for (int i = size / 2 - 1; i >= 0; i--) {
            adjust(nums, size, i);
        }
        for (int i = size - 1; i >= 1; i--) {
            swap(nums[0], nums[i]);        
            adjust(nums, i, 0);              
        }
    }
    void adjust(vector<int>& nums, int len, int index) {
        int left = 2*index + 1;   // index左子节点
        int right = 2*index + 2;  // index右子节点
        int maxIdx = index;
        if (left < len && nums[left] > nums[maxIdx]) {
            maxIdx = left;
        }
        if (right < len && nums[right] > nums[maxIdx]) {
            maxIdx = right;
        }
        if (maxIdx != index) {
            swap(nums[maxIdx], nums[index]);
            adjust(nums, len, maxIdx);
        }
    }
};