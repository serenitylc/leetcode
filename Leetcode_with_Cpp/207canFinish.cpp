// 拓扑排序：入度表 BFS
// [[1, 0]], 官方做法是 0->1。也可以根据依赖关系建图，要完成1，依赖于先完成0，所以是1->0。
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1 || prerequisites.size() == 0) return true;
        vector<int> degrees(numCourses, 0);
        unordered_map<int, vector<int>> neighbors;
        queue<int> qe;
        for (vector<int>& pre : prerequisites) {
            degrees[pre[0]]++;
            neighbors[pre[1]].push_back(pre[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) qe.push(i);
        }
        int count = 0;
        while (!qe.empty()) {
            int node = qe.front();
            for (int other_node : neighbors[node]) {
                degrees[other_node]--;
                if (degrees[other_node] == 0) qe.push(other_node);
            }
            qe.pop();
            count++;
        }
        return count == numCourses;
    }
};

// DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbors(numCourses);
        vector<int> visited(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            neighbors[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, neighbors, visited)) return false;
        }
        return true;
    }
    bool dfs(int i, vector<vector<int>>& neighbors, vector<int>& visited) {
        if (visited[i] == -1) return true;
        if (visited[i] == 1) return false;
        visited[i] = 1;
        for (auto j : neighbors[i]) {
            if (!dfs(j, neighbors, visited)) return false;
        }
        visited[i] = -1;
        return true;
    }
};