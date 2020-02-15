class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {        //选择第一个点
            unordered_map<int, int> um;                 //距离, 个数
            for(int j = 0; j < points.size(); j++) {    //选择第二个点
                if(i == j) continue;                    //如果i和j指向同一点, 跳过
                int dist2 = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + 
                            (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);  //计算距离
                um[dist2] ++;
            }
            for(auto p : um) {
                res += p.second * (p.second - 1);
            }
        }
        return res;
    }
};