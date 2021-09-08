#include <iostream>
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <vector>
using namespace std;

// #define INT_MAX 10000
int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    int m, n;
    vector<int> op(2);
    for (int i = 0; i < 2; ++i) {
        cin >> op[i];
        if (cin.get() == '\n') break;
    }
    m = op[0];
    n = op[1];
    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> nums[i][j];
        }
    }
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0) {
                for (int k = 0; k < j; ++k) {
                    if (nums[i][k] >= j-k && dp[i][k] + 1 < dp[i][j]) dp[i][j] = dp[i][k] + 1;
                }
                continue;
            }
            if (j == 0) {
                for (int t = 0; t < i; ++t) {
                    if (nums[t][j] >= i-t && dp[t][j] + 1 < dp[i][j]) dp[i][j] = dp[t][j] + 1;
                }
                continue;
            }
            for (int k = 0; k < j; ++k) {
                if (nums[i][k] >= j-k && dp[i][k] + 1 < dp[i][j]) dp[i][j] = dp[i][k] + 1;
            }
            for (int t = 0; t < i; ++t) {
                if (nums[t][j] >= i-t && dp[t][j] + 1 < dp[i][j]) dp[i][j] = dp[t][j] + 1;
            }
        }
    }
    cout << dp[m-1][n-1] << endl;
    system("pause");
    return 0;
}
