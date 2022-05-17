// 滑动窗口 s[l...r]  时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;  
        int res = 0;
        while (l < s.size()) {
            if (freq[s[r + 1]] == 0 && r + 1 < s.size())
                freq[s[++r]] ++;
            else
                freq[s[l++]] --;
            res = max(res, r - l + 1);
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int l = 0, r = 0;
        int res = 0;
        while (r < s.size()) {
            char c = s[r];
            r++;
            window[c]++;
            while (window[c] > 1) {  // 获取可行解
                char d = s[l];
                l++;
                window[d]--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};