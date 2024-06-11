class Solution
{
public:
    long long taskSchedulerII(vector<int> &tasks, int space)
    {
        unordered_map<int, long long> mp;

        long long days = 0;

        for (int task : tasks)
            if (mp.find(task) == mp.end())
                mp[task] = ++days;
            else
                mp[task] = days = max(days, mp[task] + space) + 1;

        return days;
    }
};
