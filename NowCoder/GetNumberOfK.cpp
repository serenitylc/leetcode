class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        #if 0
            int res = 0;
            for (int& val : data) {
                if (val == k) ++res;
            }
            return res;
        #endif
        return count(data.begin(), data.end(), k);
        // return (upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k));
    }
};