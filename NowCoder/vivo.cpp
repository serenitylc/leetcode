#include <iostream>
using namespace std;

int main() {
    string str;
    int res = 0;
    while (cin >> str) {
        int num = 0;
        bool flag = false;
        for (int i = 0; i < 6; ++i) {
            if (str[i] == '7') {
                flag = true;
                ++res;
                break;
            } else {
                num = num * 10 + (str[i] - '0');
            }
        }
        if (!flag && num % 7 == 0) ++res;
    }
    cout << res << endl;
    resurn 0;
}