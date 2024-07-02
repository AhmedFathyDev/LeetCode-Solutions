class Solution
{
private:
    void backtrack(vector<vector<int>> &possibleSubsets, vector<int> newSubsets, vector<int> nums, int k, int remain, int start)
    {
        if (remain < 0 || newSubsets.size() > k)
            return;
        else if (remain == 0 && newSubsets.size() == k)
            possibleSubsets.push_back(newSubsets);
        else
            for (int i = start; i < nums.size(); ++i)
            {
                newSubsets.push_back(nums[i]);
                backtrack(possibleSubsets, newSubsets, nums, k, remain - nums[i], i + 1);
                newSubsets.pop_back();
            }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> possibleSubsets;
        backtrack(possibleSubsets, {}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, k, n, 0);
        return possibleSubsets;
    }
};
