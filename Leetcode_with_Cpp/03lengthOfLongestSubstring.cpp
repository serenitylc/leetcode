// 滑动窗口 s[l...r]  时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;  
        int res = 0;
        while(l < s.size()) {
            if(freq[s[r + 1]] == 0 && r + 1 < s.size())
                freq[s[++r]] ++;
            else
                freq[s[l++]] --;
            res = max(res, r - l + 1);
        }
        return res;
    }
};