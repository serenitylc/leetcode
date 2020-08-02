class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];   // 只需按照结尾排序即可
        //return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end() ,cmp);
        int res = 1;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i][0] >= end) {
                end = intervals[i][1];
                res++;
            }
        return intervals.size() - res;
    }
};
// 贪心算法: 选择结尾最短的，后面才可能连接更多区间
// 把问题转化为最多能保留多少个区间，使他们互不重复