class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int>& w) : origin(std::move(w)) {
        partial_sum(origin.begin(), origin.end(), origin.begin());
    }
    
    int pickIndex() {
        int pos = (rand() % origin.back()) + 1;
        return lower_bound(origin.begin(), origin.end(), pos) - origin.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */