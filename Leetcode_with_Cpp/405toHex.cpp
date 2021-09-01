class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef";
        string res = "";
        while (num && res.size() < 8) {
            res = hex[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }
};

// 十六进制 to 十进制
int toDec(string hexStr) {
    int res = 0;
    int i = 0;
    for (auto & s : hexStr) {
        if (s <= '9') {
            res += (s - '0') * pow(16, s.size() - i - 1);
        } else {
            res += (s - 'A' + 10) * pow(16, s.size() - i - 1);
        }
        i++;
    }
    return res;
}