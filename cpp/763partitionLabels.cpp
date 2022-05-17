class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> mp;  // 记录字母对应的最后出现位置
        for (int i = 0; i < S.size(); ++i)
            mp[S[i]] = i;
        int start = 0, end = 0;
        for (int i = 0; i < S.size(); ++i) {
            end = max(end, mp[S[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};