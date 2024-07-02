class Solution
{
private:
    void backtrack(vector<vector<int>> &possibleSubsets, vector<int> newSubsets, vector<int> &nums, int remain, int start)
    {
        if (remain < 0)
            return;
        else if (remain == 0)
            possibleSubsets.push_back(newSubsets);
        else
            for (int i = start; i < nums.size(); ++i)
            {
                newSubsets.push_back(nums[i]);
                backtrack(possibleSubsets, newSubsets, nums, remain - nums[i], i);
                newSubsets.pop_back();
            }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> possibleSubsets;
        backtrack(possibleSubsets, {}, candidates, target, 0);
        return possibleSubsets;
    }
};
