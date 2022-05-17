class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        res.reserve(numCourses);  // only change the capacity of vector
        vector<int> degrees(numCourses, 0);
        unordered_map<int, vector<int>> neighbors;
        queue<int> qe;
        for (vector<int> & pre : prerequisites) {
            degrees[pre[0]]++;
            neighbors[pre[1]].push_back(pre[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) qe.push(i);
        }
        while (!qe.empty()) {
            int node = qe.front();
            qe.pop();
            res.push_back(node);
            for (int other_node : neighbors[node]) {
                degrees[other_node]--;
                if (degrees[other_node] == 0) qe.push(other_node);
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        res.reserve(numCourses);
        vector<int> degrees(numCourses, 0);
        unordered_map<int, vector<int>> neighbors;
        vector<int> visited(numCourses, 0);
        for (auto & p : prerequisites) {
            degrees[p[1]]++;
            neighbors[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                if (dfs(neighbors, i, visited, res)) { // ÊÇ·ñÓÐ»·
                    return vector<int>();
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
    bool dfs(unordered_map<int, vector<int>>& neighbors, int node, vector<int>& visited, vector<int>& res) {
        if (visited[node] == 2) return false;
        if (visited[node] == 1) return true;
        visited[node] = 1;
        for (int & p : neighbors[node]) {
            if (dfs(neighbors, p, visited, res)) return true;
        }
        visited[node] = 2;
        res.push_back(node);
        return false;
    }
};