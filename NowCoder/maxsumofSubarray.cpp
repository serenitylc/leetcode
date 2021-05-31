class Solution {
public:
    int maxsumofSubarray(vector<int>& arr) {
        int res = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = max(arr[i], arr[i-1] + arr[i]);
            res = max(res, arr[i]);
        }
        return res;
    }
};