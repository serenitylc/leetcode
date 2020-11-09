class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        stack<int> st;  // Next Greater Number
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && T[st.top()] <= T[i])
                st.pop();
            res[i] = st.empty() ? 0 : (st.top() - i);
            st.push(i);
        }
        return res;
    }
};