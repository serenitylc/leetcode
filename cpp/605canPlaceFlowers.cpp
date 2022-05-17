class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int cnt = 0;
        for (int i = 0; i < sz; ++i) {  // 解决数组越界问题
            if (!flowerbed[i] && !flowerbed[max(0, i-1)] && !flowerbed[min(sz-1, i+1)]) {
                flowerbed[i] = 1;
                ++cnt;
            }
        }
        return cnt >= n;
    }
};