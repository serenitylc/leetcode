class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while (!q.empty()) {
            res++;
            for (int sz = q.size(); sz > 0; sz--) {
                string cur = q.front();
                if (cur == endWord) return res;
                q.pop();
                for (auto & w: wordList) {
                    if (w.empty() || w.size() != beginWord.size()) continue;
                    int diff = 0;
                    for (int i = 0; i < w.size(); i++) {
                        if (w[i] != cur[i]) ++diff;
                        if (diff > 1) break;
                    }
                    if (diff <= 1) {
                        q.push(w);
                        w = "";
                    }
                }
            }
        }
        return 0;
    }
};