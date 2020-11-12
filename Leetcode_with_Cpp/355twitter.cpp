typedef pair<int, int> PII;

class Twitter {
private:
    unordered_map<int, unordered_set<int>> followers_;  // id - followers
    unordered_map<int, vector<PII>> contents_;  // id - {time, twitterId}
    int time = 0;
public:
    Twitter() {
        followers_.clear();
        contents_.clear();
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        contents_[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for (PII item : contents_[userId]) {
            pq.push(item);
            if (pq.size() > 10) pq.pop();
        }
        for (int followeeId : followers_[userId]) {
            for (PII item : contents_[followeeId]) {
                pq.push(item);
                if (pq.size() > 10) pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followers_[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (!followers_[followerId].count(followeeId)) return;
        followers_[followerId].erase(followeeId);
    }

};



int now_ = 0;

class Tweet {
public:
    int id;
    int time;
    Tweet *next;
    Tweet(int id) {
        this->id = id;
        this->time = now_++;
        next = nullptr;
    }
};

class User {
public:
    int id;
    Tweet *tweetHead;
    unordered_set<int> followed;
    User(int id) {
        this->id = id;
        tweetHead = nullptr;
        followed.insert(id);   // 要先把自己关注了
    }
    void follow(int followeeId) {
        if (followeeId == id) return;
        followed.insert(followeeId);
    }
    void unfollow(int followeeId) {
        if (!followed.count(followeeId) || followeeId == id) return;
        followed.erase(followeeId);
    }
    void post(int contentId) {
        Tweet *newContent = new Tweet(contentId);
        newContent->next = tweetHead;
        tweetHead = newContent;
    }
};

class Twitter {    
private:
    unordered_map<int, User*> userMap;
    bool contain(int id) {
        return userMap.find(id) != userMap.end();
    }
public:
    Twitter() {
        userMap.clear();
    }
    void postTweet(int userId, int tweetId) {
        if (!contain(userId)) {
            userMap[userId] = new User(userId);
        }
        userMap[userId]->post(tweetId);
    }
    vector<int> getNewsFeed(int userId) {
        if (!contain(userId)) return {};
        typedef function<bool(const Tweet*, const Tweet*)> Compare;
        Compare cmp = [](const Tweet *a, const Tweet *b) {
            return a->time < b->time;
        };
        priority_queue<Tweet*, vector<Tweet*>, Compare> q(cmp);
        for (int followeeId : userMap[userId]->followed) {
            if (!contain(followeeId)) {
                userMap[followeeId] = new User(followeeId);
            }
            Tweet *head = userMap[followeeId]->tweetHead;
            if (head == nullptr) continue;
            q.push(head);
        }
        vector<int> ret;
        while (!q.empty()) {
            Tweet *t = q.top(); q.pop();
            ret.push_back(t->id);
            if (ret.size() == 10) return ret;
            if (t->next) {
                q.push(t->next);
            }
        }
        return ret;
    }
    void follow(int followerId, int followeeId) {
        if (!contain(followerId)) {
            userMap[followerId] = new User(followerId);
        }
        userMap[followerId]->follow(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (!contain(followerId)) return;
        userMap[followerId]->unfollow(followeeId);
    }
};