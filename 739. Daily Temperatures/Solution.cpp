class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int temperatures_size = temperatures.size();
        vector<int> answer(temperatures_size);
        stack<int> sk;

        for (int i = temperatures_size - 1; i > -1; --i)
        {
            while (!sk.empty() && temperatures[sk.top()] <= temperatures[i])
                sk.pop();

            if (!sk.empty())
                answer[i] = sk.top() - i;

            sk.push(i);
        }

        return answer;
    }
};
