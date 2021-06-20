/* 第三题：最短路径
 * 图像从传感器到输出JPEG格式图片经过很多node处理，这些node构成一个图像处理的pipeline，其中的有些节点依赖于其他节点输出。A->B表示B的执行依赖于A。
 * 假设每个node执行时间为A(t)，即node A需要执行t秒，没有依赖的node可以并行执行。编写一个方法输入一个有向无环图pipeline，输出执行完需要的最短时间。
 * 输入：第一行输入node的执行时间，第二行输入node的依赖关系。
 * 输出：最短时间。
 *
 * 每个节点找它所有前驱节点的最大值 或者一开始就把边反着连 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int e[N], ne[N], h[N], w[N], idx;

// 拉链法建图
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// dfs深搜
int dfs(int u) {
    int s = 0;
    //遍历u结点的所有儿子
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        s = max(s, dfs(j)); // 递归求所有儿子中值最大的那个
    }
    return s + w[u]; // 返回儿子最大值+本身的消耗
}

int main() {
    memset(h, -1, sizeof(h));
    int num, k = 0;
    while (cin >> num) {
        w[++ k] = num;
        if (cin.get() == '\n') break;
    }
    vector<bool> st(k); // 记录该节点是否有父结点
    k = 1;
    while (cin >> num) {
        add(k, num);
        st[num] = true;
        char op = cin.get();
        if (op == ';') k++;
        else if (op == '\n') break;
    }
    // dfs，从每个根节点往下递归
    int ans = 0;
    for (int i = 1; i <= st.size(); i++) {
        if (st[i] == false)
            ans += dfs(i);
    }
    cout << ans;
    system("pause");
    return 0;
}