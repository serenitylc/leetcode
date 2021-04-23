class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if (array.empty()) return vector<int>{};
        int mul = INT_MAX;
        int res_l;
        int res_r;
        bool isFind = false;
        int l = 0, r = array.size() - 1;
        while (l < r) {
            if (array[l] + array[r] > sum) --r;
            else if (array[l] + array[r] < sum) ++l;
            else {
                int tmp = array[l] * array[r];
                if (tmp < mul) {
                    res_l = l;
                    res_r = r;
                    mul = tmp;
                    isFind = true;
                }
                ++l;
                --r;
            }
        }
        return isFind ? vector<int>{array[res_l],array[res_r]} : vector<int>{};
    }
};

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if (array.empty()) return vector<int>();
        int tmp = INT_MAX;
        pair<int, int> ret;
        unordered_map<int,int> mp;
        for (int i = 0; i < array.size(); ++i) {
            mp[array[i]] = i;
        }
        for (int i = 0; i < array.size(); ++i) {
            if (mp.find(sum-array[i]) != mp.end()) {
                int j = mp[sum-array[i]];
                if ( j > i && array[i]*array[j] < tmp) {
                    tmp = array[i] * array[j];
                    ret = {i, j};
                }
            }
        }
        if (ret.first == ret.second) return vector<int>();
        return vector<int>({array[ret.first], array[ret.second]});

    }
};