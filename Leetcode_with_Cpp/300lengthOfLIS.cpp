class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 二分查找 O(nlogn)
        if (nums.size() < 1) return 0;
        // 存放找到的上升子序列 (其中元素值越小越好，这样当加入一个新值的时候，构成上升子序列的可能性就越大.)
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                int aim = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[aim] = nums[i];
            }
        }
        return dp.size();
    }
};

// 给定数组arr，设长度为n，输出arr的最长递增子序列。（如果有多个答案，请输出其中 按数值(注：区别于按单个字符的ASCII码值)进行比较的 字典序最小的那个）
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        // 第一步：利用贪心+二分求最长递增子序列长度
        vector<int> res;
        vector<int> maxLen;
        if (arr.size() < 1) return res;
        res.emplace_back(arr[0]);
        maxLen.emplace_back(1);
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > res.back()) {
                res.emplace_back(arr[i]);
                maxLen.emplace_back(res.size());
            } else {
                int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
                res[pos] = arr[i];
                maxLen.emplace_back(pos+1);
            }
        }
        // 第二步：填充最长递增子序列
        for (int i = arr.size()-1, j = res.size(); j > 0; --i) {
            if (maxLen[i] == j) {
                res[--j] = arr[i];
            }
        }
        return res;
    }
};