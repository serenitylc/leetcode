// ---------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(void) {
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        } else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

list_node * check(list_node * head) {
    //////在下面完成代码
    if (!head) cout << "true" << endl;
    list_node *slow = head, *pre = NULL, *fast = head;
    while (fast && fast->next) {
        list_node* temp = slow;
        slow = slow->next;
        fast = fast->next->next;
        temp->next = pre;
        pre = temp;
    }
    if (fast) slow = slow->next;
    while (pre && slow) {
        if (pre->val != slow->val) {
            cout << "false" << endl;
            return head;
        }
        pre = pre->next;
        slow = slow->next;
    }
    cout << "true" << endl;
    return head;
}

int main () {
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}

// ---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int res = longestCommonSubsequence(str1, str2);
    cout << res << endl;
    return 0;
}

// ---------------------------------------------------------------------------------------
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


// 链表回文、最长公共子序列
// 资源管理平台难点
// 数据库容灾备份怎么做  -- 使用 mysqldump 命令备份数据库(使用 mysqlhotcopy 工具快速备份) / 实时备份主从服务器 / 使用云服务(提供主从，高可用(后台使用双主结构)等方案
// https
// 防止sql注入 -- 未经充分检查的用户输入数据，意外变成了代码被执行。 -- 没有（运行时）编译，就没有注入。
// 现在的数据库系统都提供SQL语句预编译和查询参数绑定功能，在SQL语句中放置占位符'?'，然后将带有占位符的SQL语句传给数据库编译，执行时才将用户输入作为执行参数传给用户。
// 这样操作不仅使得SQL语句在书写的时候不再需要拼接，看起来也更直接，而且用户输入的数据也没有机会被送到数据库的SQL解释器被编译执行，也不会越权变成代码。
