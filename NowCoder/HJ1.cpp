#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
//     cout << str << endl;
    int res = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] != ' ') {
            res++;
        } else {
            break;
        }
    }
    cout << res << endl;
    return 0;
}