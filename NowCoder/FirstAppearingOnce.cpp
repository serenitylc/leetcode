class Solution {
public:
    // Insert one char from stringstream
    void Insert(char ch) {
        if (mp.find(ch) == mp.end()) {
            q.push(ch);
        }
        ++mp[ch];
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!q.empty()) {
            char ch = q.front();
            if (mp[ch] == 1) return ch;
            else q.pop();
        }
        return '#';
    }
private:
    string str;
    unordered_map<char,int> mp;
    queue<char> q;
};