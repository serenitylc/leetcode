class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        while (n) {
            if (m == 0 || nums1[m - 1] <= nums2[n - 1])
                nums1[last--] = nums2[--n];
            else
                nums1[last--] = nums1[--m];
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- - 1;
        while (m >= 0 && n >= 0) {
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0) nums1[pos--] = nums2[n--];
    }
};