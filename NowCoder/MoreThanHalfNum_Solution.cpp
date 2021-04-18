class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int,int> mp;
        for (const int val : numbers) ++mp[val];
        for (const int val : numbers) {
            if (mp[val] > numbers.size() / 2 ) return val;
        }
        return 0;
    }
};

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if (numbers.empty()) return 0;
        int res = numbers[0];
        int cnt = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (cnt == 0) {
                res = numbers[i];
                cnt = 1;
            } else if (numbers[i] == res) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == res) ++cnt;
        }
        return (cnt > numbers.size() / 2) ? res : 0;
    }
};