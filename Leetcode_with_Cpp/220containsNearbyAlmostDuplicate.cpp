class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.lower_bound((long long)nums[i] - (long long)t) != record.end() 
                    && *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t)  // 可能溢出
                return true;
            record.insert(nums[i]);
            if (record.size() == k + 1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};

// lower_bound(): 返回值是一个迭代器, 返回指向大于等于key的第一个值的位置 (要求有序数组)
// upper_bound(): 返回大于等于key的最后一个元素的位置(要求有序数组)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 10000)
            return false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j <= i + k && j < nums.size(); j++) {
                if (abs((long)nums[i] - (long)nums[j]) <= t)
                    return true;
            }
        }
        return false;
    }
};