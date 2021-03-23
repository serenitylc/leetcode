/* 有一个ASCII字符串,其中包含数字和非数字,请找出其中所有的连续的数字.
 * 比如说对于字符串: abc123FGX#@AD5LKYO0936sda*xc342s&
 * 找到所有连续的数字如下:
 * 123
 * 5
 * 0936
 * 342
 */
#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // std::isdigit

using namespace std;

vector<string> FindNumbers(const string & str) {
    vector<string> res;
    enum State {NUMBER, OTHERS} state = OTHERS;
    size_t num_begin;
    for (int i = 0; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            switch (state) {
            case OTHERS:
                state = NUMBER;
                num_begin = i;
                break;
            case NUMBER:
                break;
            }
            if (i == str.size() - 1) {
                res.push_back(str.substr(num_begin, i - num_begin + 1));
            }
        } else {
            switch (state) {
            case NUMBER:
                state = OTHERS;
                res.push_back(str.substr(num_begin, i - num_begin));
            case OTHERS:
                break;
            }
        }
    }
    return res;
}

int main() {
    auto v = FindNumbers("abc123FGX#@AD5LKYO0936sda*xc342s&");
    for (string & s : v) {
        cout << s << "\n";
    }
    system("pause");
    return 0;
}