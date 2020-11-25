class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.size() == 0) st.push(s[i]);
            else if (st.top() =='(' && s[i] == ')') st.pop();
            else if (st.top() =='{' && s[i] == '}') st.pop(); 
            else if (st.top() =='[' && s[i] == ']') st.pop(); 
            else st.push(s[i]);
        }
        return st.size() == 0; 
    }
};