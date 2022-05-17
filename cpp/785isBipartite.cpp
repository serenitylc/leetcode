class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> node(n, -1);  // -1表示待染色
        for (int i = 0; i < n; ++i) {
            if (node[i] == -1 && !dfs(graph, i, node, 0)) {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, int cur, vector<int>& node, int c) {  // 返回第cur个点染c色能否成功
        if (node[cur] != -1) return node[cur] == c;  // 当前点已染色
        node[cur] = c;  // 染c色
        for (int & neigh : graph[cur]) {
            if (!dfs(graph, neigh, node, !c)) {  // 递归相邻的点，c => !c 换色 (二分图)
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (const int & j : graph[node]) {
                    if (color[j] == -1) {
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;
                    } else if (color[node] == color[j]) {
                        return false;
                    }
                }
            }
            
        }
        return true;
    }
};