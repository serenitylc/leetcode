class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        string res(l1 + l2, '0');
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                int tmp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0'); 
                res[i+j+1] = tmp % 10 + '0';
                res[i+j] += tmp / 10;
            }
        }
        for (int i = 0; i < l1 + l2; i++) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";  
    }
};