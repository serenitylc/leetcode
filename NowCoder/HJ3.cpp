#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        set<int> se;
        while (n--) {
            int tmp;
            cin >> tmp;
            se.insert(tmp);
        }
        for (auto & i : se) {
            cout << i << endl;
        }
    }
}