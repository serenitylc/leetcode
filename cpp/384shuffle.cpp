class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int>& nums) : origin(std::move(nums)) {

    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (origin.empty()) return {};
        vector<int> shuffled(origin);
        int n = origin.size();
        // 反向洗牌
        for (int i = n-1; i >= 0; --i)
            swap(shuffled[i], shuffled[rand() % (i+1)]);
        // 正向洗牌
        // for (int i = 0; i < n; ++i) {
        //    int pos = rand() % (n-i);
        //    swap(shuffled[i], shuffled[i+pos]);
        // }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */