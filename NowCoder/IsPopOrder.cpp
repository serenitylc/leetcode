class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.empty() && popV.empty()) return true;
        if (pushV.empty() || pushV.size() != popV.size()) return false;
        int i = 0, j = 0;
        stack<int> st;
        while (i < pushV.size()) {
            if (pushV[i] != popV[j]) {
                st.push(pushV[i++]);
            } else {
                ++i;
                ++j;
                while (!st.empty() && st.top() == popV[j]) {
                    st.pop();
                    ++j;
                }
            }
        }
        return st.empty();
    }
};