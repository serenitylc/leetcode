class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        deque<int> deque;
        if (num.size() == 0 || size < 1 || num.size() < size) return res;
        for (int i = 0; i < num.size(); i++) {
            if (!deque.empty() && deque.front() == i - size)  // 窗口大小超过 size, 弹出队头 (i-size+1即为首元素index)
                deque.pop_front();
            while (!deque.empty() && num[i] > num[deque.back()])
                deque.pop_back();
            deque.push_back(i);
            if (i + 1 >= size) res.push_back(num[deque.front()]);
        }
        return res;
    }
};