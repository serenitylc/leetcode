class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto c : s) mp[c]++;
        // Ä¬ÈÏÊÇ´ó¶¥¶Ñ priority_queue<int, vector<int>, less<int>> pq;
        priority_queue<pair<int, char>> pq;
        for (auto m : mp) pq.push({m.second, m.first});
        string res("");
        while (!pq.empty()) {
            // string s(num, char);
            res += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;
    }
};