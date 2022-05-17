// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         for (int i = 1; i <= m; ++i) {
//             for (int j = 1; j <= n; ++j) {
//                 if (text1[i-1] == text2[j-1])
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 else
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[m][n];
//     }
// };

// 返回公共子序列 字符串 和 长度
#include <iostream>
#include <vector>
using namespace std;

string LCS(vector<vector<string>>& mark, string & s1, const int & i, const int & j, string & res) {
    // (0-m * 0-n)网格，起点在右下角，终点是左上角
    if (i == 0 || j == 0) {
        return res;
    }
    if (mark[i][j] == "flag") {
        res = s1[i-1] + res;
        return LCS(mark, s1, i-1, j-1, res);
    } else if (mark[i][j] == "up") {
        return LCS(mark, s1, i-1, j, res);
    } else {
        return LCS(mark, s1, i, j-1, res);
    }
}

void longestCommonSubsequence(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    vector<vector<string>> mark(m+1, vector<string>(n+1, ""));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                mark[i][j] = "flag";
            } else if (dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                mark[i][j] = "up";
            } else {
                dp[i][j] = dp[i][j-1];
                mark[i][j] = "left";
            }
        }
    }
    string res("");
    string lcs = LCS(mark, s1, m, n, res);
    cout << lcs << endl;
    cout << lcs.size() << endl;
    return;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    longestCommonSubsequence(str1, str2);
    system("pause");
    return 0;
}