class Solution {
public:
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        int l = 0, r = 0;
        int res = 0;
        while (l + r < arr1.size()) {
            if (arr2[r] < arr1[l])
                res = arr2[r++];
            else
                res = arr1[l++];
        }
        return res;
    }
};