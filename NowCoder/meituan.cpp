/* #include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    string res;
    char pre;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') continue;
        if (str[i] == pre) continue;
        if (str[i] != ' ') pre = str[i];
        res += str[i];
    }
    cout << res;
    //system("pause");
    return 0;
} */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    int x[n / 2 + 1], y[n / 2 + 1];
    int index = 1;
    for (int i = 1; i <= n / 2; ++i) {
        x[i] = nums[index++];
        y[i] = nums[index++];
    }
    int dp[n / 2 + 1][n / 2 + 1];
    for (int i = 1; i <= n / 2; ++i) {
        dp[i][0] = i;
        dp[0][i] = i;
    }
    for (int i = 1; i <= n / 2; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            if (x[i] == y[i]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            } else {
                dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
            }
        }
    }
    cout << dp[n/2][n/2];
    // cout << 2;
    return 0;
}