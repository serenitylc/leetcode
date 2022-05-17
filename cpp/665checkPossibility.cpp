class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.empty() || nums.size() <= 1) return true;
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt < 2; i++) {
            if (nums[i-1] <= nums[i]) continue;
            if (i-2 >= 0 && nums[i-2] > nums[i])
                nums[i] = nums[i-1];  // 修改当前数字     2 3 3 2 4  ->  2 3 3 3 4 
            else    
                nums[i-1] = nums[i];   // 修改前面的数字  -1 4 2 3 ->  -1 2 2 3
            cnt++;
        }
        return cnt <= 1;
    }
};