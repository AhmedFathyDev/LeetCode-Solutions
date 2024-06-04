class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> chars(26, 0);

        int count = 0;

        for (char task : tasks)
        {
            chars[task - 'A']++;
            count = max(count, chars[task - 'A']);
        }

        int intervals = (count - 1) * (n + 1);

        for (int ch : chars)
            if (ch == count)
                intervals++;

        return max(intervals, (int)tasks.size());
    }
};
