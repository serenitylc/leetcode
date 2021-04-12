#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    int str[n];
    string s;
    scanf("%s", &s);
    for (int i = 0; i < n; ++i) {
        str[i] = s[i] - '0';
    }
    if (n == 1) {
        cout << str[0] << endl;
        return 0;
    }
    int last = 0;
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        if (last >= 0 && (str[i] + str[last] == 10)) {
            str[i] = 0;
            str[last] = 0;
            last -= 1;
            if (str[last] == 0) last = -1;
            flag = true;
        }
        if (last < 0) {
            last = i + 1;
            ++i;
        }
        if (!flag) ++last;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] != 0) res++;
    }
    cout << res << endl;
    system("pause");
    return 0;
}