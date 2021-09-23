// 定义一个整数数组, 判断是否存在重复元素
bool isReapted(vector<int>& nums) {
    unordered_map<int, int> ump;
    if (nums.size() <= 1) return false;
    for (int i = 0; i < nums.size(); ++i) {
        if (ump.find(nums[i]) != ump.end()) return true;
        ump[nums[i]]++;
    }
    return false;
}

// 给出小写字符组成的字符串s, 删除相邻重复的字符  abbaca --> ca  s长度不超过20000
string delelteRepeatChar(string s) {
    if (s.size() <= 1) return s;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
            int tmp = s[i++];
            while (true) {
                if (tmp == s[i]) i++;
                else break;
            }
        }
        st.push(s[i]);
    }
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}