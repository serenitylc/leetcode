class Solution {
private:
    // str[i] 向上拨动一次
    string plusOne(string str, int i) {
        str[i] = str[i] == '9' ? '0' : str[i] + 1;
        return str;
    }
    // str[i] 向下拨动一次
    string minusOne(string str, int i) {
        str[i] = str[i] == '0' ? '9' : str[i] - 1;
        return str;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        visited.insert(deadends.begin(), deadends.end()); 
        if (visited.count("0000")) return -1;
        int step = 0;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        while (!q.empty()) {            
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string cur = q.front();
                q.pop();
                if (cur == target) return step;
                for (int j = 0; j < 4; ++j) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) { q.push(up); visited.insert(up); }
                    string down = minusOne(cur, j);
                    if (!visited.count(down)) { q.push(down); visited.insert(down); }            
                }
            }
            step++;
        }
        return -1;
    }
};