class Solution {
public:
    int numSquares(int n) {
        queue< pair<int,int> > q;    // 借用队列解决 无权图结构的 BFS
        q.push(make_pair(n, 0));    // 建立图结构

        vector<bool> visited(n + 1, false);
        visited[n] = true;          // 图结构搜索路经可能重复

        while(!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i = 1;  ; i++) {
                int a = num - i * i;    // 减去平方数，获得下一个图节点位置，即是step + 1层。可能有多种情况，会到达多个节点。
                if(a < 0)
                    break;
                if(a == 0)           // 当到达0节点，说明已经走完了。由于是层序的，第一个到达0节点就直接返回步数。
                    return step + 1;
                if(!visited[a]) {
                    q.push(make_pair(a, step + 1));     // 记录到达当前节点，已经走了的步数。
                    visited[a] = true;
                }
            }
        }
        return 0;
    }
};

// n=10:    (10, 0)--(9, 1)--(6, 1)--(1, 1)--(8, 2)--(5, 2)--(0, 2)     10 = 3*3 + 1*1;  step = 2