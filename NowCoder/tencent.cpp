// 1、链表分组
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param m int整型
     * @param a ListNode类 指向彩带的起点，val表示当前节点的val，next指向下一个节点
     * @return ListNode类vector
     */
    vector<ListNode*> solve(int m, ListNode* a) {
        vector<ListNode*> res;
        unordered_map<int, vector<int>> mp;
        while (a) {
            int cur = a->val % m;
            mp[cur].push_back(a->val);
            a = a->next;
        }
        int index = 0;
        while (index < m) {
            if (!mp[index].empty()) {
                ListNode *head = new ListNode(0);
                ListNode *cur = head;
                for (auto num : mp[index]) {
                    cur->next = new ListNode(num);
                    cur = cur->next;
                }
                res.push_back(head->next);
            } else {
                res.push_back(NULL);
            }
            index++;
        }
        return res;
    }
};

// 2、魔法球
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000000007;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> arr;
        arr.reserve(n);
        long long tmp;
        while (cin >> tmp) {
            arr.push_back(tmp);
            if (cin.get() == '\n') break;
        }
        sort(arr.begin(), arr.end());
        long long res = 0;
        for (int i = n-1; i >= 0; --i) {
            res += arr[i];
            res %= N;
            for (int j = 0; j < i; ++j) {
                arr[j] += arr[i];
            }
        }
        cout << res << endl;
    }
    system("pause");
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;
    int mod = 1000000007;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<int> vec;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        long long ans = 0;
        long long sum = 0;
        for (int k = 0; k < n; k++) {
            ans += (sum + vec[k]);
            ans %= mod;
            sum += (sum + vec[k]);
            sum %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}

// 3、刻舟求剑
// 奇数和偶数分组排序，奇数遍历一次，偶数遍历一次，
// 遍历的时候，双指针首尾，首尾相加小于载重，船+1，left++， right--，大于载重，right--，船+1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool findNum(vector<int>& vec1, vector<int>& vec2, int num, int w) {
	int count = 0;
	int left = 0, right = vec1.size() - 1;
	while (left <= right) {
		if (left == right) {
			count++;
			break;
		} else {
			int v = vec1[left] + vec1[right];
			if (v <= w) {
				count++;
				left++;
				right--;
			} else {
				count++;
				right--;
			}
		}
	}
	if (count > num) return false;
	left = 0, right = vec2.size() - 1;
	while (left <= right) {
		if (left == right) {
			count++;
			break;
		} else {
			int v = vec2[left] + vec2[right];
			if (v <= w) {
				count++;
				left++;
				right--;
			} else {
				count++;
				right--;
			}
		}
	}
	return count <= num;
}

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		T--;
		int n, w;
		cin >> n >> w;
		vector<int> vec1;
		vector<int> vec2;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (tmp % 2) {
				vec1.emplace_back(tmp);
			} else {
				vec2.emplace_back(tmp);
			}
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		int left = 1, right = n, pos = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (findNum(vec1, vec2, mid, w)) {
				pos = mid;
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		cout << pos << endl;
	}
	return 0;
}

// 4、求字符串
// 维护一个严格单调递减栈即可，但维护弹栈的时候需要考虑后面的字符还够不够选
#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack<char> stk;
    for (int i = 0; i < n; i++) {
        // 维护一个严格单调递减栈
        // 如果当前字符比栈顶字符大，普通单调递减栈就是直接弹出，直接栈为空，或者遇到栈顶字符比当前字符大
        // 但是在该题中需要考虑，如果把栈的字符弹出了，后续字符还够不够选择，所以需要判断一下，也就是n - i > k的作用
        while (!stk.empty() && stk.top() < s[i] && n - i > k) {
            stk.pop();
            k++;  // 弹出一次，可选字符 k++
        }
        if (k <= 0) continue;  // 如果k小于等于0，不能加字符了
        stk.push(s[i]);
        k--;
    }
    string res = "";
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
char str[maxn];
int len;
char solve(int &pos, int minlen) {
    for (int i = pos + 1, lim = len - minlen + 1; i < lim; ++i) {
        if (str[i] > str[pos]) pos = i;
    }
    pos += 1;
    return str[pos-1];
}
int main(void) {
    int n, k, pos = 0;
    scanf("%d%d%s", &n, &k, str);
    len = strlen(str);
    for (int i = 0; i < k; ++i) {
        putchar(solve(pos, k - i));
    }
    putchar('\n');
    return 0;
}

// 第五题（动态规划题）

// n 个图块，每个图块有一个数字，数字代表一种颜色。初始选择一个魔法图块，如果包含该图块的连续个图块数字相同，就可以变色。变色需要花费的代价是两个颜色的数字的差的绝对值。求把所有图块变成相同颜色的最小代价。
// 首先，不难发现，在变色的过程中会出现一个包含 魔法图块的同颜色的区间。我们变色的过程就是不断左右扩张这个区间。变色只有两个选择，要么变成区间左边图块的颜色，要么变成右边的颜色，别的变色都是没有意义的。
// 因此，这显然是一个区间动态规划问题。

// 设dp[i][j][0/1]为所有可能的状态。第一维i代表区间左端点，第二维j代表区间右端点，第三维0/1代表区间的颜色是左端点的颜色还是右端点的颜色。设c为颜色的数组。

// 显然我们可以列出状态转移方程：
// dp[i][j][0]=min(dp[i+1][j][0]+abs(c[i]-c[i+1]),dp[i+1][j][1]+abs(c[i]-c[j]))
// dp[i][j][1]=min(dp[i][j-1][0]+abs(c[j]-c[i]),dp[i][j-1][1]+abs(c[j]-c[j-1]))
// 初始边界条件：当i==j时，dp[i][j][0]=dp[i][j][1]=0

// 根据状态转移方程，我们可以很容易求出最后的答案，即dp[0][n-1][0]和dp[0][n-1][1]中的最小值。

// 为了简化代码量，可以使用记忆化搜索。

// 最终时间复杂度为O(N^2)。题目给了N=500，说明更差的O(N^3)级别的算法也是能通过此题的。

#include<bits/stdc++.h>
using namespace std;

#define maxn 505
int ar[maxn],n;
int dp[maxn][maxn][2];
int magic = 0x3f3f3f3f;
int search(int i,int j,int k)
{
    if (dp[i][j][k]==magic)
    {
        if (k==0)
        {
            dp[i][j][k] = min
            (
                search(i + 1, j, 0)+abs(ar[i]-ar[i+1]), 
                search(i + 1, j, 1)+abs(ar[i]-ar[j])
            );
        }
        else
        {
            dp[i][j][k] = min
            (
                search(i, j - 1, 0)+abs(ar[j]-ar[i]), 
                search(i, j - 1, 1)+abs(ar[j]-ar[j-1])
            );
        }
    }
    return dp[i][j][k];
}
int main(void)
{
    int totans=magic;
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n;++i)
    {
        scanf("%d", &ar[i]);
        dp[i][i][0] = dp[i][i][1] = 0;
    }
    totans = min(search(0, n-1, 0), search(0, n-1, 1));
    printf("%d", totans);
    return 0;
}
