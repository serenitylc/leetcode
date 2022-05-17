class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, len = 0;
        stack<int> st;
        vector<int> visited(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) visited[i] = 1;
                else st.pop();
            }
        }
        while (!st.empty()) {
            visited[st.top()] = 1;
            st.pop();
        }
        for (int i = 0; i < s.size(); ++i) {
            if (visited[i] == 1) {
                len = 0;
                continue;
            }
            len++;
            res = max(res, len);
        }
        return res;
    }
};