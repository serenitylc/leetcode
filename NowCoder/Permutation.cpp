class Solution {
public:
    vector<string> res;
    vector<string> Permutation(string str) {
        string tmpStr(str);
        sort(tmpStr.begin(), tmpStr.end());  // ±£Ö¤×ÖµäÐò
        bool* visited = new bool[str.size()]{false};
        string r;
        backtrace(tmpStr, visited, r);
        return res;
    }
    void backtrace(const string& str, bool* visited, string& r) {
        if (r.size() == str.size()) {
            res.push_back(r);
            return;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (visited[i]) continue;
            if (i && str[i] == str[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            r.push_back(str[i]);
            backtrace(str, visited, r);
            visited[i] = false;
            r.pop_back();
        }
    }
};