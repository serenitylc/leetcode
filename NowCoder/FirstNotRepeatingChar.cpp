class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> mp;
        for (int i = 0; i < str.size(); ++i) {
            mp[str[i]] = i;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (mp[str[i]] == i) return i;
            else mp[str[i]] = 0;
        }
        return -1;
    }
};