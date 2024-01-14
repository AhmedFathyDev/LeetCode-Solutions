#include <bits/stdc++.h>

using namespace std;

class TimeMap
{
private:
    unordered_map<string, vector<pair<string, int>>> time_map;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        time_map[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        if (!time_map.count(key))
            return "";

        int left = 0;
        int right = time_map[key].size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (time_map[key][mid].second <= timestamp)
                left = mid + 1;
            else
                right = mid;
        }

        return left > 0 && left <= time_map[key].size() ? time_map[key][left - 1].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
