class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty())
            return "";
        int n = strs.size();
        int n1 = strs[0].size();
        for (int i = 0; i < n1; i++) {
            char c = strs[0][i];
            for (int j = 1; j < n; j++) {
                if (strs[j][i] != c)
                    return (i == 0) ? "" : strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};