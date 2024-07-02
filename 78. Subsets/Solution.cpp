class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> possibleSubsets;
        possibleSubsets.push_back({});

        for (int num : nums)
        {
            vector<vector<int>> newSubsets;

            for (vector<int> currentSubset : possibleSubsets)
            {
                vector<int> tempSubset = currentSubset;
                tempSubset.push_back(num);
                newSubsets.push_back(tempSubset);
            }

            for (vector<int> newSubset : newSubsets)
                possibleSubsets.push_back(newSubset);
        }
        return possibleSubsets;
    }
};
