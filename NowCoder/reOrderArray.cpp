class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        vector<int> res;
        res.reserve(array.size());
        for (int num : array) {
            if (num % 2) res.push_back(num);
        }
        for (int num : array) {
            if (num % 2 == 0) res.push_back(num);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        bool flag;
        for (int i = 1; i < array.size(); ++i) {
            flag = false;
            for (int j = 1; j < array.size() - i + 1; ++j) {
                if (array[j] % 2 && array[j-1] % 2 == 0) {
                    swap(array[j], array[j-1]);
                    flag = true;
                }
            }
            if (!flag) break;
        }
        return array;
    }
};