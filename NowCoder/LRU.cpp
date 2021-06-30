#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

struct Node {
    int key;
    int val;
    Node(int k = 0, int v = 0) : key(k), val(v) {}
};

class Solution {
public:
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        cap = k;
        vector<int> res;
        for (auto & input : operators) {
            if (input[0] == 1) set(input[1], input[2]);
            else res.push_back(get(input[1]));
        }
        return res;
    }
    void add(int k, int v) {
        L.push_front(Node(k, v));
        H[k] = L.begin();
        if (L.size() > cap) {
            auto last = L.end();
            --last;
            remove(last);
        }
    }
    int remove(list<Node>::iterator & it) {
        int k = it->key;
        int v = it->val;
        L.erase(it);
        H.erase(k);
        return v;
    }
    void set(int k, int v) {
        auto it = H.find(k);
        if (it != H.end()) remove(it->second);
        add(k, v);
    }
    int get(int k) {
        int val = 0;
        auto it = H.find(k);
        if (it != H.end()) {
            val = remove(it->second);
            add(k, val);
            return val;
        }
        return -1;
    }
private:
    int cap;
    list<Node> L;
    unordered_map<int, list<Node>::iterator> H;
};