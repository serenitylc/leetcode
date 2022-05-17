class Solution {
private:
    vector<int>* head;
public:
    Solution(vector<int>& nums) {
        head = &nums;
    }
    
    int pick(int target) {
        int res = -1;
        int num = 0;
        for (int i = 0; i < (*head).size(); i++) {
            if ((*head)[i] == target) {
                num++;
                if (rand() % num == 0) res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */