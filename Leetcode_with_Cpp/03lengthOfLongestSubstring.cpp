#include <iostream>
using namespace std;

// O(n^2) 动态规划，前n个元素不相等，每次增加一个元素，考虑其与前n个元素是否相等
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size, i = 0, j, k, max = 0;
        size = s.size();
        for(j = 0; j < size; j++) {  
            for(k = i; k < j; k++)
                if(s[k] == s[j]) {
                    i = k + 1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
};

int main()
{
	int value;
	Solution a;
	value = a.lengthOfLongestSubstring("abcabcbb");
	cout << "value: " << value << endl;
    system("pause");
    return 0;
}

/*
// 滑动窗口 s[l...r]  时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;  
        int res = 0;
        while(l < s.size()) {
            if(freq[s[r+1]] == 0 && r + 1 < s.size())
                freq[s[++r]] ++;
            else
                freq[s[l++]] --;
            res = max(res, r-l+1);
        }
        return res;
    }
};

*/