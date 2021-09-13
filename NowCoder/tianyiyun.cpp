#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> nums;
    int i = 0;
    int tmp;
    while (true) {
        cin >> tmp;
        if (i == 0) {
            i++;
            n = tmp;
            continue;
        }
        nums.push_back(tmp);
        if (cin.get() == '\n') break;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    system("pause");
    return 0;
}
