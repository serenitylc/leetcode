class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        int l = 1, r = 2;
        while (r > l) {
            int tmp = (l+r)*(r-l+1)/2;  // 计算区间和 [l,r]
            if (tmp < sum) ++r;
            else if (tmp > sum) ++l;
            else {
                vector<int> seq;
                for (int i = l; i <= r; ++i) {
                    seq.push_back(i);
                }
                res.push_back(seq);
                ++l;
            }
        }
        return res;
    }
};