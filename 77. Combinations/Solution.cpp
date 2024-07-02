class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> possibleSubsets;
        vector<int> newSubset(k, 0);
        int i = 0;

        while (i >= 0)
        {
            newSubset[i]++;

            if (newSubset[i] > n)
                --i;
            else if (i == k - 1)
                possibleSubsets.push_back(newSubset);
            else
                ++i, newSubset[i] = newSubset[i - 1];
        }

        return possibleSubsets;
    }
};
