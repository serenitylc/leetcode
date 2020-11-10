class Solution {
private:
    class MonotonicQueue {  // 单调队列
    private:
        deque<int> data;
    public:
        void push(int n) {
            while (!data.empty() && data.back() < n)
                data.pop_back();
            data.push_back(n);
        }
        int max() { return data.front(); }
        void pop(int n) {
            if (!data.empty() && data.front() == n)
                data.pop_front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonicQueue window;
        for (int i = 0; i < k - 1; i++)
            window.push(nums[i]);
        for (int j = k - 1; j < nums.size(); j++) {
            window.push(nums[j]);
            res.push_back(window.max());
            window.pop(nums[j - k + 1]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deque;
        for (int i = 0; i < nums.size(); i++) {
            if (!deque.empty() && deque.front() == i-k)  // 窗口大小超过 k, 弹出队头 
                deque.pop_front();
            while (!deque.empty() && nums[i] > nums[deque.back()])  // 单调队列
                deque.pop_back();
            deque.push_back(i);
            if (i >= k-1) res.push_back(nums[deque.front()]);
        }
        return res;
    }
};