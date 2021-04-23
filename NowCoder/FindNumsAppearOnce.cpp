class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        int res = 0;
        for (int & num : array) {
            res ^= num;
        }
        int index = 0;  // 根据 index 位区分 a/b
        while ((res & 1) == 0) {  // & 优先级低于 ==
            index++;
            res = res >> 1;
        }
        int a = 0, b = 0;
        for (int num : array) {
            if (partition(num, index)) {  // 根据 index 位将数组划分为两部分
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return a < b ? vector<int>{a, b} : vector<int>{b, a};
    }
    bool partition(int num, int index) {
        num = num >> index;
        return (num & 1) != 0;
    }
};

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        sort(array.begin(), array.end());
        vector<int> v;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] == array[i+1]) ++i;
            else v.push_back(array[i]);
        }
        return v;
    }
};