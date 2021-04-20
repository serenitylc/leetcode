class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        sort(numbers.begin(), numbers.end(), [&](int& a, int& b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2 < s2+s1;
        });
        for (int & num : numbers) {
            res += to_string(num);
        }
        return res;
    }
};