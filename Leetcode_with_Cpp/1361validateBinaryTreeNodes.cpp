class Solution {
private:
    int count;  // Union-Find  图的动态连通性  并查集是一种树型数据结构, 用于处理一些不相交集合的合并及查询问题
    vector<int> parent;  // 数组模拟一个森林
    vector<int> size;
    void initUF(int n) {
        count = n;
        parent.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int a) {
        while (parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }
    void uni(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        if (roota == rootb) return;
        if (size[roota] <= size[rootb]) {
            parent[roota] = rootb;
            size[rootb] += size[roota];
        } else {
            parent[rootb] = roota;
            size[roota] += size[rootb];
        }
        count--;
    }
    bool connected(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        return roota == rootb;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // 使用并查集求解, 每一次合并操作不能产生环 (与同一个集合中的元素合并), 最终集合数量为1
        initUF(n);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (connected(i, leftChild[i])) return false;  // 如果i和i的孩子节点已在同一个集合中, 那么存在环
                uni(i, leftChild[i]);
            }
            if (rightChild[i] != -1) {
                if (connected(i, rightChild[i])) return false;
                uni(i, rightChild[i]);
            }
        }
        return count == 1;
    }
};