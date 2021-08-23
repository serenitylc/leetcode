#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    char c = tolower(getchar());
    int res = 0;
    for (auto & i : str) {
        if (tolower(i) == c) {
            ++res;
        }
    }
    cout << res << endl;
}