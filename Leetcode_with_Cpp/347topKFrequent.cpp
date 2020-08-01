class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  //第一个int为元素，第二个int为频率
        // priority_queue< type, container, function >
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 小顶堆(小值优先级高)
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        for(unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if(pq.size() == k) {
                if(it->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(it->second, it->first));
                }
            }else
                pq.push(make_pair(it->second, it->first));  //第一个为频率，第二个为元素(pq 默认按照第一个元素值排序)
        }
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};