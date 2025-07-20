#include<bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    map<int, set<int>> follows;
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> allTweets;
        allTweets.insert(allTweets.end(), tweets[userId].begin(), tweets[userId].end());
        for (int user : follows[userId]) {
            allTweets.insert(allTweets.end(), tweets[user].begin(), tweets[user].end());
        }
        sort(allTweets.rbegin(), allTweets.rend());

        vector<int> res;
        for (auto x : allTweets) {
            res.push_back(x.second);
            if (res.size() == 10) break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main()
{
    Twitter obj;
    return 0;
}