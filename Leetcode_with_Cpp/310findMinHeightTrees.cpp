class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> mp;
        for (auto & edge : edges) {
            int u = edge[0], v = edge[1];
            ++degree[u];
            ++degree[v];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) q.push(i);
        }
        while (!q.empty()) {
            res.clear();
            int sz = q.size();  // q在变化，需提前记录大小
            for (int j = 0; j < sz; ++j) {
                int node = q.front();
                q.pop();
                res.push_back(node);
                --degree[node];
                for (auto & conn : mp[node]) {
                    --degree[conn];
                    if (degree[conn] == 1) q.push(conn);
                }
            }
        }
        return res;
    }
};