#include <iostream>
using namespace std;

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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;  // »¬¶¯´°¿Ú s[l...r]
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