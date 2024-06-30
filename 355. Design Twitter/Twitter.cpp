class Twitter
{
private:
    deque<pair<int, int>> tweets;
    unordered_map<int, unordered_map<int, bool>> users;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweets.push_front({tweetId, userId});
    }

    vector<int> getNewsFeed(int userId)
    {
        unordered_map<int, bool> followees = users[userId];

        int tweetsCount = 1;
        vector<int> newsFeed;

        for (pair<int, int> tweet : tweets)
            if (tweetsCount > 10)
                break;
            else if (followees[tweet.second] || tweet.second == userId)
                newsFeed.push_back(tweet.first), tweetsCount++;

        return newsFeed;
    }

    void follow(int followerId, int followeeId)
    {
        users[followerId][followeeId] = true;
    }

    void unfollow(int followerId, int followeeId)
    {
        users[followerId][followeeId] = false;
    }
};
