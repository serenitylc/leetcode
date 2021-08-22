#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000000007;
int main() {
    int T;
    cin >> T;
    vector<int> fuck;
    while (T--) {
        int n;
        cin >> n;
        vector<long> arr;
        arr.reserve(n);
        int tmp;
        while (cin >> tmp) {
            arr.push_back(tmp);
            if (cin.get() == '\n') break;
        }
        sort(arr.begin(), arr.end());
        long res = 0;
        for (int i = n-1; i >= 0; --i) {
            res += arr[i];
            for (int j = 0; j < i; ++j) {
                arr[j] += arr[i];
            }
        }
        fuck.push_back(res % N);
        //cout << res << endl;
    }
    for (auto n : fuck) {
        cout << n << endl;
    }
    system("pause");
    return 0;
}

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
        // write code here
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
