class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int max_area = 0;
        int heights_size = heights.size();

        stack<pair<int, int>> sk;

        for (int i = 0; i < heights_size; ++i)
        {
            int start = i;

            while (!sk.empty() && heights[i] < sk.top().second)
            {
                int index = sk.top().first;
                int height = sk.top().second;
                sk.pop();

                max_area = max(max_area, height * (i - index));
                start = index;
            }

            sk.push({start, heights[i]});
        }

        while (!sk.empty())
        {
            int index = sk.top().first;
            int height = sk.top().second;
            sk.pop();

            max_area = max(max_area, height * (heights_size - index));
        }

        return max_area;
    }
};
