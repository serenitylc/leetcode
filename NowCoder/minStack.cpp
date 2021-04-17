class Solution {
public:
    void push(int value) {
        st.push(value);
        if (mst.empty()) {
            mst.push(value);
        } else {
            mst.push(mst.top() >= value ? value : mst.top());
        }
    }
    void pop() {
        st.pop();
        mst.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return mst.top();
    }
private:
    stack<int> st, mst;
};