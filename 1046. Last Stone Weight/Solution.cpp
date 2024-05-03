class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;

        for (int stone : stones)
            pq.push(stone);

        int weight = 0;

        while (pq.size() > 1)
        {
            weight = pq.top();
            pq.pop();

            weight -= pq.top();
            pq.pop();

            pq.push(weight);
        }

        return pq.top();
    }
};
