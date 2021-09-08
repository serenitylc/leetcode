// 1.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> matric;
    for (int i = 0; i < N; ++i) {
        vector<int> tmp;
        int val;
        while (cin >> val) {
            tmp.push_back(val);
            if (cin.get() == '\n') break;
        }
        matric.push_back(tmp);
    }
    int scale = N * K;
    vector<vector<int>> res(scale, vector<int>(scale));
    for (int i = 0; i < scale; ++i) {
        for (int j = 0; j < scale; ++j) {
            res[i][j] = matric[i / K][j / K];
        }
    }
    for (int i = 0; i < scale; ++i) {
        for (int j = 0; j < scale; ++j) {
            cout << res[i][j];
            if (j != K * N - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

// 3.
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string s;
        cin >> s;
        string tar = s;
        sort(tar.begin(), tar.end());
        if (tar == s) {
            cout << 0 << endl;
            break;
        }
        queue<string> q;
        set<string> se;
        q.push(s);
        se.insert(s);
        int res = 0;
        while (!q.empty()) {
            res++;
            string cur = q.front();
            q.pop();
            if (cur == tar) {
                cout << res << endl;
                break;
            }
            for (int i = 1; i < cur.size(); ++i) {
                string tmp = cur.substr(0, i);
                reverse(tmp.begin(), tmp.end());
                string str = tmp + s.substr(i);
                if (se.find(str) != se.end()) continue;
                q.push(str);
                se.insert(str);
            }
        }
    }
    return 0;
}