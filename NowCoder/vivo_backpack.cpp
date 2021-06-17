#include <iostream>
#include <vector>
using namespace std;

int main() {
    int C;
    cin >> C;
    vector<int> weight;
    vector<int> value;
    weight.reserve(500);
    value.reserve(500);
    int tmp, N = 0;
    while (cin >> tmp) {
        weight.push_back(tmp);
        ++N;
        if (cin.get() == '\n') break;
    }
    while (cin >> tmp) {
        value.push_back(tmp);
        if (cin.get() == '\n') break;
    }
    vector<vector<int>> dp(N + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (weight[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j - weight[i-1]] + value[i-1], dp[i-1][j]);
            }
        }
    }
    cout << dp[N][C] << endl;
    system("pause");
    return 0;
}