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
                if (i > start && nums[i] == nums[i - 1])
                    continue; // skip duplicates

                newSubsets.push_back(nums[i]);
                backtrack(possibleSubsets, newSubsets, nums, remain - nums[i], i + 1);
                newSubsets.pop_back();
            }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> possibleSubsets;
        sort(candidates.begin(), candidates.end());
        backtrack(possibleSubsets, {}, candidates, target, 0);
        return possibleSubsets;
    }
};
